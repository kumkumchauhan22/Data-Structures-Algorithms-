/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        
        
        int good = (node->val >= maxSoFar) ? 1 : 0;
        int newMax = max(maxSoFar, node->val);
        
        good += dfs(node->left, newMax);
        good += dfs(node->right, newMax);
        
        return good;
    }
};
