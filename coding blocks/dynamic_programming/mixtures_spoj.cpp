#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll,ll> dp[101][101];
ll colors[101];

ll heat_generated;

pair<ll,ll> min_heat(int start, int end) {
    if(dp[start][end].first!=-1)
        return dp[start][end];
    if(start==end) {
        dp[start][end]=make_pair(0,colors[start]);
        return dp[start][end];
    }

    ll least_heat=10e9;
    pair<ll,ll> mix1,mix2;

    for(int i=start;i<end;i++) {
        pair<ll,ll> return1 = min_heat(start,i);
        pair<ll,ll> return2 = min_heat(i+1,end);
        ll stage_heat=return1.first+return2.first+(return1.second*return2.second);
        if(least_heat>stage_heat) {
            least_heat=stage_heat;
            mix1=return1;
            mix2=return2;
        }
    }
    heat_generated=least_heat;
    dp[start][end]=make_pair(heat_generated,(mix1.second+mix2.second)%100);
    return dp[start][end];
}

int main() {
    int n;
    while(scanf("%d", &n)==1) {
        heat_generated=0;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>colors[i];

        // for(int i=0;i<n;i++) {
        //     cout<<colors[i]<<" ";
        // }
        // cout<<endl;

        min_heat(1,n);
        cout<<dp[1][n].first<<endl;
    }
    return 0;
}
