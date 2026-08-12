class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq; // frequency map
        int left = 0, ans = 0;

        for(int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            // shrink window if any element exceeds k frequency
            while(freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
