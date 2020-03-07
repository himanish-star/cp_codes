#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    vector<ll> allFactors[100001];
    for(int i=1;i<=100000;i++) {
        ll num=i*i;
        for(int j=1;j*j<=i;j++) {
            if(num%j==0) {
                if(num/j==j) {
                    allFactors[i].push_back(j); 
                } else {
                    allFactors[i].push_back(j);
                    allFactors[i].push_back(num/j);
                }
            }
        }
    }

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
            um1[arr1[i]]++;
        }
        
        for(ll i=0;i<m;i++) {
            if(arr2[i]==0)
                nyz++;
            um2[arr2[i]]++;
        }

        ll ans=0;
        for(ll i=0;i<n;i++) {
            ll num=arr1[i]*arr1[i];
            for(ll j=1;j*j<=abs(arr1[i]);j++) {
                if(num%j==0) {
                    if (num/j == j) {
                        if(um2[j] && um2[-j]) {
                            um2[j]--;
                            um2[-j]--;
                            ans++;
                        }
                    } else if(abs(arr1[i])/j==j) {
                        if(um2[j] && um2[-num/j]) {
                            um2[j]--;
                            um2[-num/j]--;
                            ans++;
                        } 
                        if(um2[-j] && um2[num/j]) {
                            um2[-j]--;
                            um2[num/j]--;
                            ans++;
                        }
                    } else {
                        if(um2[j] && um2[-num/j]) {
                            um2[j]--;
                            um2[-num/j]--;
                            ans++;
                        } 
                        if(um2[-j] && um2[num/j]) {
                            um2[-j]--;
                            um2[num/j]--;
                            ans++;
                        }

                        ll ld=abs(arr1[i])/j;
                        if(um2[ld] && um2[-num/ld]) {
                            um2[ld]--;
                            um2[-num/ld]--;
                            ans++;
                        } 
                        if(um2[-ld] && um2[num/ld]) {
                            um2[-ld]--;
                            um2[num/ld]--;
                            ans++;
                        }
                    }
                }
            }
        }
        
        for(ll i=0;i<m;i++) {
            ll num=arr2[i]*arr2[i];
            for(ll j=1;j*j<=abs(arr2[i]);j++) {
                if(num%j==0) {
                    if (num/j == j) {
                        if(um1[j] && um1[-j]) {
                            um1[j]--;
                            um1[-j]--;
                            ans++;
                        }
                    } else if(abs(arr2[i])/j==j) {
                        if(um1[j] && um1[-num/j]) {
                            um1[j]--;
                            um1[-num/j]--;
                            ans++;
                        } 
                        if(um1[-j] && um1[num/j]) {
                            um1[-j]--;
                            um1[num/j]--;
                            ans++;
                        }
                    } else {
                        if(um1[j] && um1[-num/j]) {
                            um1[j]--;
                            um1[-num/j]--;
                            ans++;
                        } 
                        if(um1[-j] && um1[num/j]) {
                            um1[-j]--;
                            um1[num/j]--;
                            ans++;
                        }

                        ll ld=abs(arr2[i])/j;
                        if(um1[ld] && um1[-num/ld]) {
                            um1[ld]--;
                            um1[-num/ld]--;
                            ans++;
                        } 
                        if(um1[-ld] && um1[num/ld]) {
                            um1[-ld]--;
                            um1[num/ld]--;
                            ans++;
                        }
                    } 
                }
            }
        }
        
        if(nxz || nyz) {
            ans+=(n-nxz)*(m-nyz);
        }
        
        printf("%lld\n",ans);
    }
    return 0;
}