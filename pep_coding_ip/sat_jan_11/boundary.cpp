/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

void getLeftBoundary(TreeNode* root, vector<int> &lb) {
    if(!root) return;
    
    
    if(!root->left && !root->right) {
        return;
    }
    lb.push_back(root->val);
    if(root->left)
        getLeftBoundary(root->left, lb);
    else if(root->right)
        getLeftBoundary(root->right, lb);
}


void getRightBoundary(TreeNode* root, vector<int> &rb) {
    if(!root) return;
    
    
    if(!root->left && !root->right) {
        return;
    }
    rb.push_back(root->val);
    if(root->right)
        getRightBoundary(root->right, rb);
    else if(root->left)
        getRightBoundary(root->left, rb);
}

void getLeaves(TreeNode* root, vector<int> &lvs) {
    if(!root) return;
    
    
    if(!root->left && !root->right) {
        lvs.push_back(root->val);
        return;
    }
    if(root->left)
        getLeaves(root->left, lvs);
    if(root->right)
        getLeaves(root->right, lvs);
}

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        vector<int> res;
        if(!root) return res;
        
        vector<int> lb; getLeftBoundary(root->left, lb);
        vector<int> lvs; getLeaves(root, lvs);
        vector<int> rb; getRightBoundary(root->right, rb);
        
        res.push_back(root->val);
        for(int i=0;i<lb.size();i++)
            res.push_back(lb[i]);
        
         for(int i=0;i<lvs.size();i++)
            res.push_back(lvs[i]);
        
        reverse(rb.begin(), rb.end());
        for(int i=0;i<rb.size();i++)
            res.push_back(rb[i]);
            
        return res;
    }
};