#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;

    int mod=1000000007;
    
    while(t--) {
        int n,k;
        cin>>n>>k;
        
        if(n==1) {
            cout<<k<<endl;
            continue;
        } 
        
        if(n==2) {
            cout<<k*k<<endl;
            continue;
        }
        
        ll dp[n+1]={0};
        
        dp[1]=k;
        dp[2]=k*k;
        
        for(int i=3;i<=n;i++) {
            dp[i]=(dp[i-1]*(k-1))%mod+(dp[i-2]*(k-1))%mod;
            dp[i]%=mod;
            if(dp[i]<0)
                dp[i]+=mod;
        }
        
        cout<<dp[n]<<endl;
    }
    return 0;
}