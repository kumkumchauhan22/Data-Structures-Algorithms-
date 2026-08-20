class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        int n = nums.size();

        // Step 1: First two operations
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Step 2: Process remaining elements
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Step 3: Concatenate arr1 and arr2
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
