/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int pre = 0;
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return root;
        
        bstToGst(root->right);
        root->val+=pre;
        pre=root->val;
        bstToGst(root->left);
        
        return root;
    }
};