#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        if(!n)
            return 0;
                
        if(n==1)
            return 0;
        
        int dp[n]={0};
        
        for(int i=1;i<n;i++) {
            dp[i]=0;
            for(int j=i;j>=0;j--) {
                if(j==0 || j==1) {
                    if(prices[i]>prices[j])
                        dp[i]=max(dp[i],prices[i]-prices[j]);
                } else if(j==i) {
                    dp[i]=max(dp[i],dp[j-1]);
                } else {
                    if(prices[i]>prices[j])
                        dp[i]=max(dp[i],prices[i]-prices[j]+dp[j-2]);  
                }
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        return dp[n-1];
    }
};