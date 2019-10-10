#include<bits/stdc++.h>

using namespace std;

int countPS(string str)
{
   int len=str.size();
   
   int dp[len][len]={0};
   
   for(int l=1;l<=len;l++) {
       for(int i=0;i+l-1<len;i++) {
           int j=i+l-1;
           if(l==1) {
               dp[i][j]=1;
           } else if(l==2) {
             if(str[i]==str[j]) {
                 dp[i][j]=3;
             } else {
                 dp[i][j]=2;
             }
           } else {
               if(str[i]!=str[j]) {
                   dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
               } else {
                   dp[i][j]=1+dp[i+1][j]+dp[i][j-1];
               }
           }
       }
   }
   return dp[0][len-1];
}