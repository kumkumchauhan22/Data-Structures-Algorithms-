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
 //DFS Implementation
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Base Case for traversing and comparing 
        if(root==NULL) return false;
        targetSum-=root->val;
        if(!root->left && !root->right){
            if(targetSum==0) return true;
        }
         bool left=hasPathSum(root->left, targetSum);
         bool right=hasPathSum(root->right, targetSum);
         return left|| right ;

        
    }
};