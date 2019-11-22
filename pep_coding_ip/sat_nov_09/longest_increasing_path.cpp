class Solution {
    int moves[4][2]={
        {+1,0},  
        {-1,0},  
        {0,+1},  
        {0,-1},  
    };
    
    void dfs(int x,int y,vector<vector<int>> &dp,vector<vector<int>> &matrix) {
        if(dp[x][y]!=1)
            return;
        
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<4;i++) {
            int nnx=x+moves[i][0];
            int nny=y+moves[i][1];
            
            if(nnx>=n || nnx<0 || nny>=m || nny<0) {
                continue;
            }
            
            if(matrix[x][y]<matrix[nnx][nny]) {
                dfs(nnx,nny,dp,matrix);
                dp[x][y]=max(dp[x][y],1+dp[nnx][nny]);
            }
        }
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()) {
            return 0;
        }
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j]==1)
                    dfs(i,j,dp,matrix);
            }
        }
        
        int ans=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<dp[i][j]<<" ";
                ans=max(ans,dp[i][j]);
            }
            cout<<endl;
        }
        
        return ans;
    }
};