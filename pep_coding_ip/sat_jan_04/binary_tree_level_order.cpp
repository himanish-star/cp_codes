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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        
        vector<vector<int>> res;
        if(!root)
            return res;
        while(qu.size()) {
            int lc = qu.size();
            vector<int> lres;
            while(lc--) {
                TreeNode *f = qu.front(); qu.pop();
                lres.push_back(f->val);
                if(f->left)
                    qu.push(f->left);
                if(f->right)
                    qu.push(f->right);
            }
            res.push_back(lres);
        }
        
        return res;
    }
};