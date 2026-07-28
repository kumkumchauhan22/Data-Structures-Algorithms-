class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int right=0,left=0;
        int zeros_cnt=0,max_len=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]==0){
                zeros_cnt++;
            }
            while(zeros_cnt>1){
                if(nums[left]==0){
                    zeros_cnt--;
                }
                left++;
            }
            int curr_length=right-left;
            max_len=max(max_len,curr_length);
            right++;
        }
        return max_len;
        
    }
};