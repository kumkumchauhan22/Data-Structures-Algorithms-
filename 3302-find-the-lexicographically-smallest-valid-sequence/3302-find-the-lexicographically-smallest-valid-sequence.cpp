class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> ans;
        vector<int> suf(n + 1, 0);

        // Step 1: Precompute suffix matches
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (suf[i] < m && word1[i] == word2[m - suf[i] - 1]) {
                suf[i] = suf[i + 1] + 1;
            }
        }

        // Step 2: Build sequence
        int j = 0, mismatches = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (mismatches == 0 && suf[i + 1] >= m - j - 1) {
                // allow mismatch only if suffix can still complete
                ans.push_back(i);
                j++;
                mismatches++;
            }
        }

        if ((int)ans.size() == m && mismatches <= 1) return ans;
        return {};
    }
};
