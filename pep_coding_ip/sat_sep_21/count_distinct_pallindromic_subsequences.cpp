#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int len=S.size();
        
        int dp[4][len][len]={0};
        
        int mod=1000000007;
        
        for(int l=1;l<=len;l++) {
            for(int i=0;i+l-1<len;i++) {
                for(int x=0;x<4;x++) {
                    int j=i+l-1;
                    dp[x][i][j]=0;
                    
                    if(l==1) {
                        if(S[i]=='a'+x)
                            dp[x][i][j]=1;
                        else
                            dp[x][i][j]=0;
                        continue;
                    }
                    
                    if(l==2 && S[i]==S[j] && S[i]=='a'+x) {
                        dp[x][i][j]=2;
                        continue;
                    } 
                     
                    
                    if(S[i]!='a'+x) {
                        dp[x][i][j]=dp[x][i+1][j];
                        continue;
                    }
                    
                    if(S[j]!='a'+x) {
                        dp[x][i][j]=dp[x][i][j-1];
                        continue;
                    }
                    
                    dp[x][i][j]=2;
                    for(int k=0;k<4;k++) {
                        dp[x][i][j]+=dp[k][i+1][j-1];
                        dp[x][i][j]%=mod;
                    }
                }
            }
        }
        
        int ans=0;
        for(int x=0;x<4;x++) {
            ans+=dp[x][0][len-1];
            ans%=mod;
        }
        
        return ans;
    }
};