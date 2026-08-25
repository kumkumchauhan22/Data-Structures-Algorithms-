class Solution {
public:
    void all_subsets(int i, vector<int>& cur_subset, vector<vector<int>>& final_ans, vector<int>& nums) {
        if (i == nums.size()) {
            final_ans.push_back(cur_subset);
            return;
        }
    
        cur_subset.push_back(nums[i]);
        all_subsets(i + 1, cur_subset, final_ans, nums);

      
        cur_subset.pop_back();
        all_subsets(i + 1, cur_subset, final_ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_subset;
        vector<vector<int>> final_ans;
        all_subsets(0, cur_subset, final_ans, nums);
        return final_ans;
    }
};
