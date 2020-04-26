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
    struct Amount {
        int exc;
        int inc;
    };
    
    Amount traverse(TreeNode* root) {
        Amount f;
        if(root) {
            Amount l=traverse(root->left);
            Amount r=traverse(root->right);
            f.inc=root->val+l.exc+r.exc;
            f.exc=max(l.exc+r.exc,max(l.exc+r.inc,max(l.inc+r.exc,l.inc+r.inc)));
            return f;
        }
        f.inc=0, f.exc=0;
        return f;
    }
public:
    int rob(TreeNode* root) {
        Amount ans=traverse(root);
        return max(ans.inc, ans.exc);
    }
};