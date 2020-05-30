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

struct E {
        TreeNode* n;
        int vi;
        int hi;
    };

bool comp(E &a, E &b) {
        if(a.hi==b.hi) {
            return a.n->val<b.n->val;
        }
        return a.hi<b.hi;
    }

class Solution {
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        queue<E> qu;
        
        qu.push(E{root,0,0});
        
        unordered_map<int,vector<E>> umap;
        int min_left=INT_MAX,max_right=INT_MIN;
        while(qu.size()) {
            int lc=qu.size();
            while(lc--) {
                E f=qu.front(); qu.pop();

                umap[f.vi].push_back(f);
                
                max_right=max(max_right,f.vi);
                min_left=min(min_left,f.vi);
                
                
                
                if(f.n->right) {
                    qu.push(E{f.n->right,f.vi+1,f.hi+1});
                }
                
                if(f.n->left) {
                    qu.push(E{f.n->left,f.vi-1,f.hi+1});
                }
            }
        }
        
        // printf("minLeft: %d, maxRight: %d\n",min_left,max_right);
        for(int i=min_left;i<=max_right;i++) {
            vector<int> la;
            if(umap[i].size()) sort(umap[i].begin(),umap[i].end(),comp);
            for(int j=0;j<umap[i].size();j++) {
                la.push_back(umap[i][j].n->val);
            }
            // sort(la.begin(),la.end());
            if(la.size())
                res.push_back(la);
        }
        
        
        return res;
    }
};