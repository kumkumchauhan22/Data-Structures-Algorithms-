class Solution {
public:
    void all_permutations(int i, vector<vector<int>> &final_ans, vector<int> &nums) {
        if (i == nums.size()) {
            final_ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            all_permutations(i + 1, final_ans, nums);
            swap(nums[i], nums[j]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> final_ans;
        all_permutations(0, final_ans, nums);
        return final_ans;
    }
};
