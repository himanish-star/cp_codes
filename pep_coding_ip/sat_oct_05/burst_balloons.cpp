#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        
        if(!n)
            return 0;
        
        if(n==1)
            return nums[0];
        
        int dp[n][n]={0};
        
        for(int l=1;l<=n;l++) {
            for(int i=0;i+l-1<n;i++) {
                int j=i+l-1;
                dp[i][j]=0;
                int numsLeft= (i-1)>=0 ? nums[i-1]:1;
                int numsRight= (j+1)<n ? nums[j+1]:1;
                for(int k=i;k<=j;k++) {
                    int dpLeft= (k-1)>=i ? dp[i][k-1]:0;
                    int dpRight= (k+1)<=j ? dp[k+1][j]:0;
                        
                    dp[i][j]=max(dp[i][j],(numsLeft*nums[k]*numsRight)+dpLeft+dpRight);
                }
            }
        }
        
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[0][n-1];
    }
};