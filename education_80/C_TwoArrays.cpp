#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

vector<vector<ll>> dp(1005,vector<ll>(15,0));

int main() {
    ll N,M;
    cin>>N>>M;

    for(ll m=0;m<=M;m++) {
        for(ll n=0;n<=N;n++) {
            if(n==0) {
                dp[n][m]=0;
                continue;
            }

            if(m==0) {
                dp[n][m]=1;
                continue;
            }

            if(n==1 && m==1) {
                dp[n][m]=1;
                continue;
            }

            ll ans = 0;
            
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    if(i<=j) {
                        ans=(ans+dp[j-i+1][m-1])%mod;
                    }
                }
            }
            dp[n][m]=ans%mod;
        }
    }

    cout<<dp[N][M]<<endl;
    return 0;
}