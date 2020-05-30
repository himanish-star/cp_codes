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
    TreeNode* temp;
    
    bool lcaUtil(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return false;
        
        // if(root==p || root==q)
        //     return true;
        
        bool rb=lcaUtil(root->right,p,q);
        bool lb=lcaUtil(root->left,p,q);
        
        if(root==p && (rb || lb)) {
            temp=root;
            return true;
        } else if(root==q && (rb || lb)) {
            temp=root;
            return true;
        } else if(lb && rb) {
            temp=root;
            return true;
        } else if(root==p || root==q) {
            return true;
        }
        return rb||lb;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        temp=NULL;
        if(!root) return temp;
        
        lcaUtil(root, p, q);
        return temp;
    }
};