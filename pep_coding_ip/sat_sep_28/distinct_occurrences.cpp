#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=t.size();
        int n2=s.size();
        
        if(!n1 || !n2)
            return 0;
        
        ll dp[n1+1][n2+1];
        
        for(int i=0;i<=n1;i++)
            dp[i][0]=0;
        for(int j=0;j<=n2;j++)
            dp[0][j]=0;
        
        for(int j=0;j<n2;j++) {
            if(t[0]==s[j]) {
                dp[1][j+1]=1+dp[1][j];
            } else {
                dp[1][j+1]=dp[1][j];
            }
        }
        
        for(int i=2;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                if(t[i-1]==s[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                } else {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        
        // for(int i=0;i<=n1;i++) {
        //     for(int j=0;j<=n2;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n1][n2];
    }
};