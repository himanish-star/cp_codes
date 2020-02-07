#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll arr1[n], arr2[n];
        for(ll i=0;i<n;i++) {
            cin>>arr1[i];
        }
        for(ll i=0;i<n;i++) {
            cin>>arr2[i];
        }

        sort(arr1,arr1+n);
        sort(arr2,arr2+n);

        ll ans=0;
        for(ll i=0;i<n;i++) {
            ans+=min(arr1[i],arr2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}