class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= high) temp.push_back(nums[j++]);

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }

    void mergesort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergesort(nums, low, mid);
            mergesort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
