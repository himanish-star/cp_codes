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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())
            return NULL;
        
        int root_val = preorder[0];
        
        int idx=0;
        vector<int> left_inorder, left_preorder;
        for(;idx<inorder.size();idx++) {
            if(root_val==inorder[idx]) {
                break;
            }
            left_inorder.push_back(inorder[idx]);
            left_preorder.push_back(preorder[idx+1]);
        }
        
        vector<int> right_inorder, right_preorder;
        idx++;
        for(;idx<inorder.size();idx++) {
            right_inorder.push_back(inorder[idx]);
            right_preorder.push_back(preorder[idx]);
        }
        
        TreeNode* root=new TreeNode(root_val);
        root->left=buildTree(left_preorder, left_inorder);
        root->right=buildTree(right_preorder, right_inorder);
        
        return root;
    }
};