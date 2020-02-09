#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n,p;
        cin>>n>>p;

        ll arr1[n],modc[n]={0};
        bool oneExist=false;
        for(ll i=0;i<n;i++) {
            cin>>arr1[i];
            if(p%arr1[i]) {
                modc[i]=1;
                oneExist=true;
            }
        }
        
        sort(arr1,arr1+n);

        if(!oneExist) {
            vector<ll> divs;
            for(ll i=0;i<n;i++) {
                if(p%arr1[i]==0 && arr1[i]!=1)
                    divs.push_back(arr1[i]);
            }
            if(divs.size()>1) {
                bool somePair=false;
                ll idx1,idx2,gc1,gc2;
                for(ll i=0;i<divs.size();i++) {
                    if(i+1<divs.size()) {
                        ll c1=(p)/(divs[i+1]);
                        c1--;
                        ll c2=ceil((p-(c1*divs[i+1]))/(double)divs[i]);
                        
                        if(c1*divs[i+1]+c2*divs[i]<=p 
                        || (c1-1)*divs[i+1]+c2*divs[i]>=p
                        || c1*divs[i+1]+(c2-1)*divs[i]>=p)
                            continue;
                        
                        somePair=true;
                        idx1=i;
                        gc1=c2;
                        gc2=c1;
                        idx2=i+1;
                        break;
                    }
                }
                if(!somePair)
                    cout<<"NO"<<endl;
                else {
                    cout<<"YES ";
                    if(arr1[0]==1)
                        cout<<0<<" ";
                    for(ll i=0;i<divs.size();i++) {
                        if(i==idx1) {
                            cout<<gc1<<" ";
                            cout<<gc2<<" ";
                            i++;
                        } else {
                            cout<<0<<" ";
                        }
                    }
                    cout<<endl;
                }
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            cout<<"YES ";
            bool notused = true;
            for(int i=0;i<n;i++) {
                if(modc[i]==1 && notused) {
                    notused=false;
                    ll val=ceil(p/(double)(arr1[i]));
                    cout<<val<<" ";
                } else {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}