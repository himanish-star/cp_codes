#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int w;
        cin>>n>>w;

        int vals[n], weights[n];
        for(int i=0;i<n;i++)
            cin>>vals[i];

        for(int i=0;i<n;i++)
            cin>>weights[i];
        
        int dp[n+1][w+1];

        for(int i=0;i<=n;i++) {
            dp[i][0]=0;
        }

        for(int i=0;i<=w;i++) {
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=w;j++) {
                if(weights[i-1]>j) {
                    dp[i][j]=dp[i-1][j];
                } else {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]] + vals[i-1]);
                }
            }
        }

        cout<<dp[n][w]<<endl;
    }

    return 0;
}