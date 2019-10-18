#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++) {
            dp[i]=0;
            for(int j=1;j<i;j++) {
                dp[i]=max(dp[i],dp[i-j]*j);
                dp[i]=max(dp[i],(i-j)*j);
            }
        }
        
        return dp[n];
    }
};