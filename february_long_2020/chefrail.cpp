#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n,m;
        cin>>n>>m;

        ll arr1[n],sqr1[n],arr2[m],sqr2[m];
        unordered_map<ll,ll> um1,um2;
        ll nxz=0,nyz=0;
        for(ll i=0;i<n;i++) {
            cin>>arr1[i];
        }
        for(ll i=0;i<m;i++) {
            cin>>arr2[i];
        }

        for(ll i=0;i<n;i++) {
            if(arr1[i]==0)
                nxz++;
            // sqr1[i]=arr1[i]*arr1[i];
            um1[arr1[i]]++;
            // prllf("(%d,sqr: %d,cnt: %d)",arr1[i],sqr1[i],um1[sqr1[i]]);
        }
        // cout<<endl;
        
        for(ll i=0;i<m;i++) {
            if(arr2[i]==0)
                nyz++;
            // sqr2[i]=arr2[i]*arr2[i];
            um2[arr2[i]]++;
            // prllf("(%d,sqr: %d,cnt: %d)",arr2[i],sqr2[i],um2[sqr2[i]]);
        }
        // cout<<endl;

        ll ans=0;
        for(ll i=0;i<n;i++) {
            ll num=arr1[i]*arr1[i];
            for(ll j=1;j<=sqrt(num);j++) {
                if(num%j==0) {
                    if (num/j == j) {
                        if(um2[j] && um2[-j]) {
                            ans++;
                        }
                    } else {
                        if(um2[j] && um2[-num/j]) {
                            ans++;
                        } 
                        if(um2[-j] && um2[num/j]) {
                            ans++;
                        }
                    } 
                }
            }
        }
        
        for(ll i=0;i<m;i++) {
            ll num=arr2[i]*arr2[i];
            for(ll j=1;j<=sqrt(num);j++) {
                if(num%j==0) {
                    if (num/j == j) {
                        if(um1[j] && um1[-j]) {
                            ans++;
                        }
                    } else {
                        if(um1[j] && um1[-num/j]) {
                            ans++;
                        } 
                        if(um1[-j] && um1[num/j]) {
                            ans++;
                        }
                    } 
                }
            }
        }
        
        if(nxz || nyz) {
            ans+=(n-nxz)*(m-nyz);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}