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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> qu; qu.push(root);
        
        while(qu.size()) {
            int ls = qu.size(); int copyls = ls;
            double avg = 0;
            while(ls--) {
                TreeNode *f = qu.front(); qu.pop();
                avg += f->val;
                if(f->left)
                    qu.push(f->left);
                if(f->right)
                    qu.push(f->right);
            }
            res.push_back(avg/copyls);
        }
        return res;
    }
};