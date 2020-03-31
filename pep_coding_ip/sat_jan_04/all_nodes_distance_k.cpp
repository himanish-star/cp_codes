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
    int tidx, ttarget;
    unordered_map<int,int> idxval;
    void traverse(TreeNode *root, TreeNode *parent, int idx, unordered_map<int,vector<int>> &adj) {
        if(!root)
            return;
        idxval[idx]=root->val;
        if(root->val==ttarget)
            tidx=idx;
        if(parent)
            adj[idx].push_back((idx-1)/2);
        if(root->left)
            adj[idx].push_back(2*idx+1);
        if(root->right)
            adj[idx].push_back(2*idx+2);
        traverse(root->left, root, 2*idx+1, adj);
        traverse(root->right, root, 2*idx+2, adj);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        ttarget = target->val;
        unordered_map<int,vector<int>> adj;
        traverse(root, NULL, 0, adj);
        vector<int> res;
        
        queue<int> qu; qu.push(tidx);
        unordered_map<int,int> vis;
        while(K--) {
            int lc = qu.size();
            while(lc--) {
                int f=qu.front(); qu.pop();
                if(vis[f])
                    continue;
                
                vis[f]=1;
                for(int i=0;i<adj[f].size();i++) {
                    if(!vis[adj[f][i]])
                        qu.push(adj[f][i]);
                }
            }
        }
        
        while(qu.size()) {
            res.push_back(idxval[qu.front()]);
            qu.pop();
        }
        return res;
    }
};