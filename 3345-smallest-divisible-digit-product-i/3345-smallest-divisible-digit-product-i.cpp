class Solution {
public:
    int smallestNumber(int n, int t) {
        // Brute force: check numbers starting from n
        for (int x = n; ; x++) {
            int prod = 1;
            int temp = x;
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            if (prod % t == 0) {
                return x;
            }
        }
    }
};
