class Solution {
public:
    int missingInteger(vector<int>& nums) {
        //  Find longest increasing prefix sum
        int prefixSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            } else break;
        }

        //  Put all elements in a set for quick lookup
        unordered_set<int> st(nums.begin(), nums.end());

        //  Find smallest integer >= prefixSum not in nums
        int candidate = prefixSum;
        while (st.count(candidate)) {
            candidate++;
        }
        return candidate;
    }
};
