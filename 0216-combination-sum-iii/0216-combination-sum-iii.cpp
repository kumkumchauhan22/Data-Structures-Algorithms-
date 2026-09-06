class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        
        function<void(int,int,int)> backtrack = [&](int start, int remain, int count) {
            if (remain == 0 && count == 0) {
                result.push_back(current);
                return;
            }
            if (remain < 0 || count < 0) return;
            
            for (int i = start; i <= 9; i++) {
                current.push_back(i);
                backtrack(i + 1, remain - i, count - 1);
                current.pop_back();
            }
        };
        
        backtrack(1, n, k);
        return result;
    }
};