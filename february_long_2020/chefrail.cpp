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
            sqr1[i]=arr1[i]*arr1[i];
            um1[sqr1[i]]++;
            // prllf("(%d,sqr: %d,cnt: %d)",arr1[i],sqr1[i],um1[sqr1[i]]);
        }
        // cout<<endl;
        
        for(ll i=0;i<m;i++) {
            if(arr2[i]==0)
                nyz++;
            sqr2[i]=arr2[i]*arr2[i];
            um2[sqr2[i]]++;
            // prllf("(%d,sqr: %d,cnt: %d)",arr2[i],sqr2[i],um2[sqr2[i]]);
        }
        // cout<<endl;

        ll ans=0;
        for(ll i=0;i<n;i++) {
            for(ll j=i+1;j<n;j++) {
                ll hpt=abs(arr1[i]-arr1[j]);
                if(((hpt*hpt)-(sqr1[i]+sqr1[j]))%2==0) {
                    ll val=((hpt*hpt)-(sqr1[i]+sqr1[j]))/(2);
                    ans+=um2[val];
                }
            }
        }

        for(ll i=0;i<m;i++) {
            for(ll j=i+1;j<m;j++) {
                ll hpt=abs(arr2[i]-arr2[j]);
                if(((hpt*hpt)-(sqr2[i]+sqr2[j]))%2==0) {
                    ll val=((hpt*hpt)-(sqr2[i]+sqr2[j]))/(2);
                    ans+=um1[val];
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