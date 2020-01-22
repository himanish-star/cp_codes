#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> divs;
        unordered_map<ll,ll> atnds;
        for(ll i=2;i<=sqrt(n);i++) {
            if(n%i==0) {
                if(n/i==i) {
                    divs.push_back(i);
                    atnds[i]=1;
                } else {
                    divs.push_back(i);
                    divs.push_back(n/i);
                    atnds[i]=1;
                    atnds[n/i]=1;
                }
            }
        }

        bool found=false;
        for(ll i=0;i<divs.size();i++) {
            for(ll j=i+1;j<divs.size();j++) {
                ll n1=divs[i];
                ll n2=divs[j];

                ll n3=n/(n1*n2);
                if(n1!=n2 && n2!=n3 && n1!=n3 && atnds[n3]==1) {
                    found=true;
                    cout<<"YES"<<endl;
                    cout<<n1<<" "<<n2<<" "<<n3<<endl;
                    break;
                }
            }
            if(found)
                break;
        }

        if(!found)
            cout<<"NO"<<endl;
    }
}