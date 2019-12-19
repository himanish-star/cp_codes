class Solution {
public:
    
    bool isEndReachable;
    
    int dfs(vector<vector<int>> &grid,int r1,int c1,int r2,vector<vector<vector<int>>> &dp) {
        int c2=r1+c1-r2;
        int n=grid.size();
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || c2<0)
            return 0;
        
        if(r1==n-1 && c1==n-1 && r2==n-1 && grid[r1][c1]!=-1) {
            isEndReachable=true;
            return 1;
        }
        
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return 0;
        
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        
        int ans=0;
        bool t1=false,t2=false;
        if(grid[r1][c1]==1) {
            ans++;
            t1=true;
            grid[r1][c1]=0;
        }
        
        if(grid[r2][c2]==1) {
            ans++;
            t2=true;
            grid[r2][c2]=0;
        }
        
        int m[4][3]={
            {1,0,0},
            {1,0,1},
            {0,1,0},
            {0,1,1},
        };
        
        int lans=0;
        for(int i=0;i<4;i++) {
            lans = max(lans,dfs(grid,r1+m[i][0],c1+m[i][1],r2+m[i][2],dp));
        }
        
        if(t1)
            grid[r1][c1]=1;
        if(t2)
            grid[r2][c2]=1;
        
        if(!lans)
            return dp[r1][c1][r2]=0;
        ans += lans;
        return dp[r1][c1][r2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        isEndReachable = false;
        
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1)));
        
        int ans = dfs(grid,0,0,0,dp);
        if(isEndReachable) {
            if(grid[n-1][n-1]==0)
                ans--;
            return ans;
        }
        return 0;
    }
};