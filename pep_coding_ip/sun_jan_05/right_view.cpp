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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.size()) {
            int lc=qu.size();
            int val;
            while(lc--) {
                TreeNode *f=qu.front();
                qu.pop();
                val=f->val;
                if(f->left)
                    qu.push(f->left);
                if(f->right)
                    qu.push(f->right);
            }
            res.push_back(val);
        }
        return res;
    }
};