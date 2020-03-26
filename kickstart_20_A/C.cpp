#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    ll id=1;
    while(t--) {
        ll n,k;
        cin>>n>>k;

        vector<ll> times(n);
        for(ll i=0;i<n;i++)
            cin>>times[i];

        priority_queue<pair<ll,pair<ll,ll>>> pq;
        for(ll i=0;i<n-1;i++) {
            pq.push({times[i+1]-times[i],{times[i],times[i+1]}});
        }
        
        for(ll i=0;i<k;i++) {
            pair<ll,pair<ll,ll>> t=pq.top();
            if(t.first<=1)
                break;
            pq.pop();
            ll mid=(t.second.first+t.second.second)*0.5;
            pq.push({mid-t.second.first,{t.second.first,mid}});
            pq.push({t.second.second-mid,{mid,t.second.second}});
        }

        printf("Case #%lld: %lld\n",id,pq.top().first);
        // vector<ll> res;
        // while(pq.size()) {
        //     pair<ll,pair<ll,ll>> t=pq.top();
        //     pq.pop();
        //     res.push_back(t.second.first);
        // }

        // sort(res.begin(),res.end());
        // for(int i=0;i<res.size();i++) {
        //     cout<<res[i]<<" ";
        // }
        // cout<<endl;
        id++;
    }
}