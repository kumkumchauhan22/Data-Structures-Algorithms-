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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> my_ans;
        if(root == NULL) return my_ans;
        
        queue<TreeNode*> my_q;
        my_q.push(root);
        
        while(!my_q.empty()){
            int q_size = my_q.size();  
            for(int i = 0; i < q_size; i++){  
                TreeNode* temp = my_q.front();
                my_q.pop();
                
                
                if(i == q_size - 1) my_ans.push_back(temp->val);
                
                if(temp->left) my_q.push(temp->left);
                if(temp->right) my_q.push(temp->right);
            }
        }
        return my_ans;
    }
};
