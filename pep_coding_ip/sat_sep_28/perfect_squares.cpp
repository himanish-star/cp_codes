#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int n1=ceil(sqrt(n));
        
        if(n<3)
            return n;
            
        
        int dp[n+1];
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
                
        for(int i=3;i<=n;i++) {
            dp[i]=INT_MAX;
            for(int j=1;j<=n1;j++) {
                if((j*j)<=i) {
                    dp[i]=min(dp[i],1+dp[i-(j*j)]);
                }
            }
        }
        
        for(int i=0;i<=n;i++)
            cout<<dp[i]<<" ";
        
        
        return dp[n];
    }
};