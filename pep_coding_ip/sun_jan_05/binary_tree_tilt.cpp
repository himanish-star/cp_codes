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
    int tiltSum;
    int trv(TreeNode *root) {
        if(!root)
            return 0;
        int sr=trv(root->right), sl=trv(root->left);
        tiltSum+=abs(sr-sl);
        return sr+sl+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        tiltSum=0;
        trv(root);
        return tiltSum;
    }
};