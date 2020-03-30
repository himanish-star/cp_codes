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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        
        vector<int> res; stack<TreeNode*> st;
        while(st.size() || curr!=NULL) {
            while(curr) {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            res.push_back(st.top()->val); st.pop();
            curr = curr->right;
        }
        
        return res;
    }
};