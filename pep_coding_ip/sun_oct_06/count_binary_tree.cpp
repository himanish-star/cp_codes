#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int dfs(int n,vector<int>& dp) {
        
        if(n==0)
            return 1;
        
        if(dp[n])
            return dp[n];
        
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans+=(dfs(i-1,dp)*dfs(n-i,dp));
        }
        return dp[n]=ans;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1);
        return dfs(n,dp);
    }
};