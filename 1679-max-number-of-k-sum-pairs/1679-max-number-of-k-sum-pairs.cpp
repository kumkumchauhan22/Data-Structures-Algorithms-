class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for (int n : nums) {
            int target = k - n;
            if (mp[target] > 0) {
                mp[target]--;
                count++;
            } else {
                mp[n]++;
            }
        }
        return count;
    }
};
