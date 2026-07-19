class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        string result = "";

        // Count the frequency of each character 
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : s) {
            count[c - 'a']--;
            
            if (visited[c - 'a']) {
                continue;
            }

            
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};