class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1000000007;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';
            dp[i] = (dp[i - 1] * 2) % MOD;
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;
            }
            last[ch] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};
