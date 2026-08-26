class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        int n = s.size();
        
        // collect indices of '1'
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones.push_back(i);
        }
        
        if ((int)ones.size() < k) return "";
        
        string ans = "";
        int minLen = n + 1;
        
        // sliding window over positions of '1'
        for (int i = 0; i + k - 1 < (int)ones.size(); i++) {
            int left = ones[i];
            int right = ones[i + k - 1];
            string candidate = s.substr(left, right - left + 1);
            
            if ((int)candidate.size() < minLen) {
                minLen = candidate.size();
                ans = candidate;
            } else if ((int)candidate.size() == minLen && candidate < ans) {
                ans = candidate;
            }
        }
        
        return ans;
    }
};
