#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin>>n;

    ll X=0;
    vector<ll> ele(n,0);
    for(ll i=0;i<n;i++) {
        cin>>ele[i];
    }

    vector<int> pos(35,0);
    for(ll i=0;i<n;i++) {
        ll temp=ele[i];
        ll cnt=0;
        while(temp) {
            if(temp & 1) {
                // cout<<"wo"<<ele[i]<<endl;
                pos[cnt]=1;
            }
            cnt++;
            temp>>=1;
        }
    }

    for(int i=0;i<35;i++) {
        if(pos[i]) {
            X=X+(1<<i);
        }
    }

    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans=max(ans,X^ele[i]);
    }

    cout<<X<<endl;
    cout<<ans<<endl;
}