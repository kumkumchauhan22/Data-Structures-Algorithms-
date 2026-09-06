class Solution {
public:
    void all_combinations(int index, int target, vector<int> &curr_comb, vector<vector<int>> &final_ans, vector<int> &arr){
        if(index==arr.size()){
            if(target==0){
                final_ans.push_back(curr_comb);
            }
            return;
        }
        if(arr[index]<=target){
            curr_comb.push_back(arr[index]);
            all_combinations(index, target-arr[index], curr_comb, final_ans, arr);
            curr_comb.pop_back();
        }
        all_combinations(index+1, target, curr_comb, final_ans, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr_comb;
        vector<vector<int>> final_ans;   
        all_combinations(0,target, curr_comb, final_ans, candidates);
        return final_ans; 
    }
};