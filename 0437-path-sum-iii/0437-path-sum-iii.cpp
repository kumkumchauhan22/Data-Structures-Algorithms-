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
    int all_traversal(TreeNode* root, long long  targetSum){
        if(root==NULL) return 0;
        int cnt=0;
        targetSum-=root->val;
        if(targetSum==0)cnt++;
        cnt+=all_traversal(root->left,targetSum);
        cnt+=all_traversal(root->right,targetSum);
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int path =0;

        //traversal start from which node dfs started 
        path+=all_traversal(root, targetSum);
        path+=pathSum(root->left,targetSum);
        path+=pathSum(root->right,targetSum);
        return path;
        
        
    }
};