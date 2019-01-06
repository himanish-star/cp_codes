#include<bits/stdc++.h>

using namespace std;

int m,n,p;
vector<pair<int,int> > vpii;

#define mod 1000000007
#define ll long long

int main() {
    cin>>m>>n>>p;


    ll dp[m+1][n+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=p;i++) {
        int x,y;
        cin>>x>>y;

        dp[x][y]=-1;
    }

    if(dp[1][1]!=-1)
    dp[1][1]=1;

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(dp[i][j]==-1) {
                dp[i][j]=0;
                continue;
            }
            if(i==1 && j==1)
                continue;

            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;

        }
    }

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[m][n];
    return 0;
}
