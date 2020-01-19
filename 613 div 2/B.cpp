#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> cumsum(n,0),arr(n,0);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }

        cumsum[0]=arr[0];
        for(ll i=1;i<n;i++) {
            cumsum[i]=cumsum[i-1]+arr[i];
            // cout<<cumsum[i]<<" ";
        }
        // cout<<endl;

        bool gono=false;

        for(ll i=0;i<n;i++) {
            if(arr[i]>=cumsum[n-1]) {
                gono=true;
                break;
            }

            if(i>0 && cumsum[i-1]>=cumsum[n-1]) {
                gono=true;
                break;
            }

            if(cumsum[n-1]-cumsum[i]>=cumsum[n-1]) {
                gono=true;
                break;
            }
        }

        
        if(gono)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}