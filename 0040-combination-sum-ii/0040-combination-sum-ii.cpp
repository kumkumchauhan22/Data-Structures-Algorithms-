class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        
        function<void(int,int)> backtrack = [&](int start, int remain) {
            if (remain == 0) {
                result.push_back(current);
                return;
            }
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i-1]) continue; 
                if (candidates[i] > remain) break;
                current.push_back(candidates[i]);
                backtrack(i + 1, remain - candidates[i]); 
                current.pop_back();
            }
        };
        
        backtrack(0, target);
        return result;
    }
};