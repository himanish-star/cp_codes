#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

int main() {
    int t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> x(2*n);
        map<ll,ll> occr;
        ll gsum=0;
        ll allZero=0;
        for(ll i=0;i<2*n;i++) {
            cin>>x[i];
            allZero+=(x[i]==0);
            gsum+=x[i];
            occr[x[i]]++;
        }

        ll tsum=gsum/(n+1);
        ll nop=0, ans=1;

        if(allZero==2*n) {
            cout<<1<<endl;
            continue;
        }

        map<pair<ll,ll>,ll> cnts;
        set<pair<ll,ll>> unq;
        for(ll i=0;i<x.size();i++) {
            if(occr[x[i]]<=0)
                continue;

            if(x[i]==tsum-x[i] && occr[x[i]]>=2) {
                occr[x[i]]-=2;
                unq.insert(make_pair(x[i],x[i]));
                cnts[make_pair(x[i],x[i])]++;
                nop++;
                continue;
            }

            if(x[i]!=tsum-x[i] && occr[tsum-x[i]]>=1) {
                occr[x[i]]--;
                occr[tsum-x[i]]--;
                nop++;
                ans=(ans*2)%mod;
                
                ll v1=min(x[i],tsum-x[i]);
                ll v2=max(x[i],tsum-x[i]);
                unq.insert(make_pair(v1,v2));
                cnts[make_pair(v1,v2)]++;
                continue;
            }
            
            if(tsum==x[i] && occr[x[i]]>=1) {
                nop++;
                occr[x[i]]--;
                occr[0]--;
                continue;
            }
        }

        // printf("nop -> %lld\n",nop);
        if(nop!=n+1) {
            cout<<0<<endl;
            continue;
        }

        //factorial
        ll fact=1;
        map<ll,ll> mp;
        for(ll i=1;i<=nop-2;i++) {
            fact=(fact*i)%mod;
            mp[i]=fact;
        }
        
        ans=(ans*fact)%mod;

        for(set<pair<ll,ll>>::iterator it=unq.begin();it!=unq.end();it++) {
            ll v1=it->first;
            ll v2=it->second;
            // cout<<"mp"<<mp[cnts[make_pair(v1,v2)]]<<endl;
            ans/=mp[cnts[make_pair(v1,v2)]];
        }

        cout<<ans<<endl;
    }
    return 0;
}