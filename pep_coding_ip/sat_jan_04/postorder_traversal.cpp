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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        
        vector<int> res; stack<TreeNode*> st;
        while(curr || st.size()) {
            while(curr) {
                st.push(curr);
                res.push_back(curr->val);
                curr = curr->right;
            }
            
            curr = st.top()->left; st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};