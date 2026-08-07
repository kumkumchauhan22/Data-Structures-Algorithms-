#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    bool factorize(long long t, Factors& f) {
        while (t % 2 == 0) { f.c2++; t /= 2; }
        while (t % 3 == 0) { f.c3++; t /= 3; }
        while (t % 5 == 0) { f.c5++; t /= 5; }
        while (t % 7 == 0) { f.c7++; t /= 7; }
        return t == 1;
    }

    int minDigitsNeeded(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        int count = c5 + c7;
        count += c3 / 2;
        c3 %= 2;

        count += c2 / 3;
        c2 %= 3;

        if (c3 == 1 && c2 == 1) {
            count += 1;
        } else {
            count += c3;
            count += (c2 == 2 ? 1 : c2);
        }
        return count;
    }

    string buildSuffix(int len, int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        string res = "";
        for (int i = 0; i < len; ++i) {
            for (int d = 1; d <= 9; ++d) {
                int nc2 = c2, nc3 = c3, nc5 = c5, nc7 = c7;
                if (d == 2) nc2--;
                else if (d == 3) nc3--;
                else if (d == 4) nc2 -= 2;
                else if (d == 5) nc5--;
                else if (d == 6) { nc2--; nc3--; }
                else if (d == 7) nc7--;
                else if (d == 8) nc2 -= 3;
                else if (d == 9) nc3 -= 2;

                if (minDigitsNeeded(nc2, nc3, nc5, nc7) <= len - 1 - i) {
                    res += to_string(d);
                    c2 = nc2; c3 = nc3; c5 = nc5; c7 = nc7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors targetFactors;
        if (!factorize(t, targetFactors)) return "-1";

        int n = num.size();
        vector<Factors> prefixFactors(n + 1);
        int zeroIdx = -1;

        for (int i = 0; i < n; ++i) {
            prefixFactors[i + 1] = prefixFactors[i];
            int d = num[i] - '0';
            if (d == 0) {
                zeroIdx = i;
                break;
            }
            if (d == 2) prefixFactors[i + 1].c2++;
            else if (d == 3) prefixFactors[i + 1].c3++;
            else if (d == 4) prefixFactors[i + 1].c2 += 2;
            else if (d == 5) prefixFactors[i + 1].c5++;
            else if (d == 6) { prefixFactors[i + 1].c2++; prefixFactors[i + 1].c3++; }
            else if (d == 7) prefixFactors[i + 1].c7++;
            else if (d == 8) prefixFactors[i + 1].c2 += 3;
            else if (d == 9) prefixFactors[i + 1].c3 += 2;
        }

        // Check if num itself (or full prefix before 0) satisfies target
        if (zeroIdx == -1) {
            Factors cur = prefixFactors[n];
            int req2 = targetFactors.c2 - cur.c2;
            int req3 = targetFactors.c3 - cur.c3;
            int req5 = targetFactors.c5 - cur.c5;
            int req7 = targetFactors.c7 - cur.c7;
            if (minDigitsNeeded(req2, req3, req5, req7) <= 0) {
                return num;
            }
        }

        int maxMatch = (zeroIdx == -1) ? n - 1 : zeroIdx;

        // Try prefix matching up to index i, changing digit at i to d > num[i]
        for (int i = maxMatch; i >= 0; --i) {
            int startDigit = num[i] - '0' + 1;
            for (int d = startDigit; d <= 9; ++d) {
                Factors cur = prefixFactors[i];
                if (d == 2) cur.c2++;
                else if (d == 3) cur.c3++;
                else if (d == 4) cur.c2 += 2;
                else if (d == 5) cur.c5++;
                else if (d == 6) { cur.c2++; cur.c3++; }
                else if (d == 7) cur.c7++;
                else if (d == 8) cur.c2 += 3;
                else if (d == 9) cur.c3 += 2;

                int remLen = n - 1 - i;
                int req2 = targetFactors.c2 - cur.c2;
                int req3 = targetFactors.c3 - cur.c3;
                int req5 = targetFactors.c5 - cur.c5;
                int req7 = targetFactors.c7 - cur.c7;

                if (minDigitsNeeded(req2, req3, req5, req7) <= remLen) {
                    string ans = num.substr(0, i) + to_string(d);
                    ans += buildSuffix(remLen, req2, req3, req5, req7);
                    return ans;
                }
            }
        }

        // If length n isn't enough, expand to higher length
        int targetLen = max(n + 1, minDigitsNeeded(targetFactors.c2, targetFactors.c3, targetFactors.c5, targetFactors.c7));
        return buildSuffix(targetLen, targetFactors.c2, targetFactors.c3, targetFactors.c5, targetFactors.c7);
    }
};