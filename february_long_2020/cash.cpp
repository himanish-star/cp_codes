#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n,k;
        cin>>n>>k;

        ll arr1[n];
        for(ll i=0;i<n;i++) {
            cin>>arr1[i];
        }

        ll ans=0;
        for(ll i=0;i<n;i++) {
            ans+=arr1[i];
        }
        cout<<ans%k<<endl;
    }
    return 0;
}