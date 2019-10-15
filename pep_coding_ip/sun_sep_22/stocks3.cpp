#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfitUtil(int k, vector<int>& prices) {
        int n=prices.size();
        
        if(!n)
            return 0;
        
        int dp[k+1][n+1]={0};
        
        for(int i=0;i<=k;i++) {
            dp[i][0]=0;
        }
        
        for(int j=0;j<=n;j++) {
            dp[0][j]=0;
        }
        
        for(int i=1;i<=k;i++) {
            int y=-prices[0]+dp[i-1][1];
            for(int j=2;j<=n;j++) {
                dp[i][j]=prices[j-1]+y;
                
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                
                y=max(y,-prices[j-1]+dp[i-1][j]);
            }
        }
        
        // for(int i=0;i<=k;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[k][n];
    }
    int maxProfit(vector<int>& prices) {
        return maxProfitUtil(2,prices);
    }
};