class Solution {
public:
    
    int dfs(vector<vector<vector<int>>> &dp,vector<int> &boxes,int i,int j,int k) {
        // remove alone the ith and all k boxes = k+1
        if(i>j)
            return 0;
        
        if(i==j)
            return (k+1)*(k+1);
        
        if(dp[i][j][k])
            return dp[i][j][k];
        
        int ans = dfs(dp,boxes,i+1,j,0) + (k+1)*(k+1);
        
        for(int e=j;e>=i;e--) {
            if(boxes[e]==boxes[i])
                ans = max(ans, dfs(dp,boxes,i,e-1,k+1) + dfs(dp,boxes,e+1,j,0));
        }
        
        return dp[i][j][k] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,0)));
        
        return dfs(dp,boxes,0,n-1,0);
    }
};