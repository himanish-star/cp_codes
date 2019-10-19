#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
        vector<vector<int>> dp(n, vector<int>(n,0));
      
       for(int i=0;i<n;i++)
           dp[i][i]=a[i];
       for(int i=0;i<n-1;i++)
           dp[i][i+1] = (a[i]|a[i+1]) + max(a[i], a[i+1]);
 
       for(int gap=2;gap<n;gap++){
           for(int i=0,j=i+gap;j<n;j++, i++){
               int maxi = INT_MIN;
               // int l=0;
               dp[i][j]=0;
               for(int k=i;k<=j;k++)
                   dp[i][j]|=a[k];
               maxi = max(maxi, dp[i+1][j]);
               maxi = max(maxi, dp[i][j-1]);
               for(int k=i+1;k<j;k++){
                   maxi = max(maxi, (dp[i][k-1]|dp[k+1][j]));
               }               
               dp[i][j]+=maxi;
           }
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cout<<dp[i][j]<<" ";
           }
           cout<<endl;
       }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}
