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
private:
    int gans;
    
    int util(TreeNode *root) {
        if(!root)
            return 0;
        
        int left = util(root->left);
        int right = util(root->right);
        
        gans = max(gans,max(root->val,max(root->val+right,max(root->val+left,root->val+left+right))));
        return max(root->val,max(root->val+left,root->val+right));
    }
public:
    int maxPathSum(TreeNode* root) {
        gans=INT_MIN;
        util(root);
        return gans;
    }
};