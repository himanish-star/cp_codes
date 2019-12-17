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
    int minCameraCoverUtil(TreeNode *root, int coveredByParent,int coveredBySelf,map<int,map<int,map<int,int>>> &dp,int idx) {
        if(!root)
            return 0;
        
        if(dp[idx][coveredByParent][coveredBySelf]!=0)
            return dp[idx][coveredByParent][coveredBySelf];
        
        int gblAns;
        if(coveredByParent) {
            gblAns = minCameraCoverUtil(root->left,0,0,dp,2*idx+1)+minCameraCoverUtil(root->right,0,0,dp,2*idx+2);
            gblAns = min(gblAns,1 + minCameraCoverUtil(root->left,1,0,dp,2*idx+1)+minCameraCoverUtil(root->right,1,0,dp,2*idx+2));
        } else if(coveredBySelf) {
            gblAns = 1 + minCameraCoverUtil(root->left,1,0,dp,2*idx+1)+minCameraCoverUtil(root->right,1,0,dp,2*idx+2);
        } else {
            gblAns = INT_MAX;
            
            if(root->left) {
                 gblAns = minCameraCoverUtil(root->left,0,1,dp,2*idx+1)+minCameraCoverUtil(root->right,0,0,dp,2*idx+2);
            } 
            
            if(root->right) {
                 gblAns = min(gblAns,minCameraCoverUtil(root->left,0,0,dp,2*idx+1)+minCameraCoverUtil(root->right,0,1,dp,2*idx+2));
            }
            
            if(root->left && root->right) {
                gblAns = min(gblAns,minCameraCoverUtil(root->left,0,1,dp,2*idx+1)+minCameraCoverUtil(root->right,0,1,dp,2*idx+2));
            } 
                        
            if(gblAns==0)
                gblAns=INT_MAX;
            gblAns = min(gblAns,1 + minCameraCoverUtil(root->left,1,0,dp,2*idx+1)+minCameraCoverUtil(root->right,1,0,dp,2*idx+2));
        }
        // cout<<root->val<<", mc = "<<gblAns<<endl;
        dp[idx][coveredByParent][coveredBySelf] = gblAns;
        return gblAns;
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->right && !root->left)
            return 1;
        
        map<int,map<int,map<int,int>>> dp;
        return minCameraCoverUtil(root,0,0,dp,0);
    }
};