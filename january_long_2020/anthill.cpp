#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n,m,a,r;
    cin>>n>>m>>a>>r;

    vector<pair<ll,ll>> p;
    ll x,y;
    for(ll i=0;i<m;i++) {
        cin>>x>>y;
        p.push_back({x,y});
    }

    cout<<m<<endl;
    for(ll i=0;i<m;i++) {
        cout<<1<<" "<<1<<" "<<p[i].first<<" "<<p[i].second<<endl;
    }
    
}