#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,l,r;

int mod = 1000000007;

int dp[3][200001];

ll occr[3];

ll calc(int sum,int counter) {
    if(dp[sum][counter]!=-1)
        return dp[sum][counter];

    if(!counter) {
        if(sum%3==0)
            return dp[sum][counter]=1;
        else
            return dp[sum][counter]=0;
    }
    ll res=0;
    for(int i=0;i<3;i++)
        res=(res+(occr[i]*calc((sum+i)%3,counter-1))%mod)%mod;
    return dp[sum][counter]=res;
}

int main() {
    cin>>n>>l>>r;

    memset(occr,0,sizeof(occr));
    memset(dp,-1,sizeof(dp));

    for(ll i=l;i<=r;i++)
      occr[i%3]++;

    ll res=0;
    for(int i=0;i<3;i++)
        res=(res+(occr[i]*calc(i,n-1))%mod)%mod;
    cout<<res<<endl;
    return 0;
}
