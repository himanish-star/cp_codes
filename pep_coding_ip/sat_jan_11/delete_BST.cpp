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
private:
    
    int pos=-1;
    
    void getInorder(TreeNode* root, int key, vector<pair<TreeNode*,TreeNode*>> &ino, TreeNode* parent) {
        if(!root)
            return;            
        
        getInorder(root->left, key, ino, root);
                
        ino.push_back({root, parent});
        if(root->val==key)
            pos=ino.size()-1;
        
        getInorder(root->right, key, ino, root);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        vector<pair<TreeNode*,TreeNode*>> ino; TreeNode* ref=new TreeNode(INT_MIN); ref->right=root;
        getInorder(ref, key, ino, NULL);
        
        if(pos==-1)
            return root;
        
        while(pos<ino.size()-1) {
            ino[pos].first->val=ino[pos+1].first->val;
            // cout<<ino[pos].first->val<<","<<pos<<" ";
            pos++;
            
            if(ino[pos].first->left==NULL && ino[pos].first->right==NULL)
                break;
        }
        if(ino[pos].second->right==ino[pos].first) {
            ino[pos].second->right=ino[pos].first->left;
        }
        
        else if(ino[pos].second->left==ino[pos].first) {
            ino[pos].second->left=NULL;
        }
        
        return ref->right;
    }
};