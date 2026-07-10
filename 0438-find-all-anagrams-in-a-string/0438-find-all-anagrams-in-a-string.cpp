class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if(s.size() < p.size())
            return ans;

        vector<int> freqP(26,0);
        vector<int> window(26,0);

        for(char c : p)
            freqP[c-'a']++;

        int left = 0;

        for(int right = 0; right < s.size(); right++) {

            window[s[right]-'a']++;

            if(right - left + 1 > p.size()) {
                window[s[left]-'a']--;
                left++;
            }

            if(right - left + 1 == p.size()) {

                if(window == freqP)
                    ans.push_back(left);
            }
        }

        return ans;
    }
};