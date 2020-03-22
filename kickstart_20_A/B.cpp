#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    int id=1;
    while(t--) {
        int n,k,p;
        cin>>n>>k>>p;

        vector<vector<int>> stacks(n,vector<int> (k,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                cin>>stacks[i][j];
            }   
        }

        for(int i=0;i<n;i++) {
            for(int j=1;j<k;j++) {
                stacks[i][j]+=stacks[i][j-1];
            }   
        }


        vector<vector<int>> dp(n+1,vector<int> (p+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=p;j++) {
                dp[i][j]=0;
                for(int x=0;x<min(j,k);x++) {
                    dp[i][j]=max(dp[i][j],stacks[i-1][x]+dp[i-1][j-(x+1)]);
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                }
            }
        }

        int ans=dp[n][p];

        printf("Case #%d: %d\n",id,ans);
        // for(int i=0;i<=n;i++) {
        //     for(int j=0;j<=p;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        id++;
    }
}