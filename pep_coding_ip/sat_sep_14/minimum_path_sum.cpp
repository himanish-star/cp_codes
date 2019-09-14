#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=m;i++)
            dp[n][i]=INT_MAX;
        
        for(int i=0;i<=n;i++)
            dp[i][m]=INT_MAX;
        
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int min_cost=min(dp[i+1][j],dp[i][j+1]);
                if(min_cost==INT_MAX) {
                    dp[i][j]=grid[i][j];
                } else {
                    dp[i][j]=grid[i][j] + min_cost;
                }
            }
        }
        
        return dp[0][0];
    }
};