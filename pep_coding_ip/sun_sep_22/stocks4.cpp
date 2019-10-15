#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        if(!n)
            return 0;
        
        if(k>n/2) {
            int profit=0;
            for(int i=1;i<n;i++) {
                if(prices[i]-prices[i-1]>0) {
                    profit+=prices[i]-prices[i-1];
                }
            }
            return profit;
        }
        
        
        vector<int> top(n+1),bottom(n+1);
        
        for(int i=1;i<=k;i++) {
            int y=-prices[0]+top[1];
            for(int j=2;j<=n;j++) {
                bottom[j]=prices[j-1]+y;
                
                bottom[j]=max(bottom[j],bottom[j-1]);
                
                y=max(y,-prices[j-1]+top[j]);
            }
            top=bottom;
        }
        
        // for(int i=0;i<=k;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return top[n];
    }
};