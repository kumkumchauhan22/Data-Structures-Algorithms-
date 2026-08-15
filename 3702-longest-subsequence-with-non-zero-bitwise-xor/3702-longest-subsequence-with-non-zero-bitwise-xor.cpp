class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        for (int x : nums) totalXor ^= x;
        int n = nums.size();
        
        // Case 1: Entire array XOR is non-zero → whole array works
        if (totalXor != 0) return n;
        
        // Case 2: Entire array XOR is zero
        // If all elements are zero, no non-zero subsequence exists
        bool allZero = true;
        for (int x : nums) {
            if (x != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) return 0;
        
        // Otherwise, remove any one element → length = n - 1
        return n - 1;
    }
};
