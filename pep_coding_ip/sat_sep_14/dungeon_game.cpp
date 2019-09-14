#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=m;i++) {
            dp[n][i]=INT_MAX;
        }
        
        for(int i=0;i<=n;i++) {
            dp[i][m]=INT_MAX;
        }
                
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int min_cost=min(dp[i+1][j],dp[i][j+1]);
                
                if(min_cost==INT_MAX) {
                    dp[i][j]=dungeon[i][j]<0 ? 1-dungeon[i][j] : 1;
                } else {
                    int value=min_cost-dungeon[i][j];
                    dp[i][j]=value>0 ? value : 1;
                }
            }
        }
        
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[0][0];
    }
};