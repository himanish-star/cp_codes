#include<bits/stdc++.h>

using namespace std;

typedef int ll;

#define mod 1000000007

vector<vector<ll>> mtrx(300005,vector<ll> (8,0));


ll N,M,ans1,ans2;
ll lo=0,hi=1000000000;

bool check(ll x) {
    vector<ll> gp(300,-1);
    for(ll i=0;i<N;i++) {
        ll k=0;
        for(ll j=0;j<M;j++) {
            if(mtrx[i][j]>=x)
                k|=(1<<j);
        }
        gp[k]=i;
    }

    ll val=(1<<M);

    for(ll i=0;i<val;i++) {
        if(gp[i]==-1)
            continue;
        for(ll j=0;j<val;j++) {
            if(gp[j]==-1)
                continue;
            
            if((i|j)==val-1) {
                ans1=gp[i];
                ans2=gp[j];
                // cout<<"found --> "<<x<<" "<<ans1+1<<","<<ans2+1<<endl;
                return true;
            }
        }
    }

    return false;
}

int main() {
    
    cin>>N>>M;

    for(ll i=0;i<N;i++) {
        for(ll j=0;j<M;j++) {
            cin>>mtrx[i][j];
        }
    }

    // cout<<endl;
    // for(ll i=0;i<N;i++) {
    //     for(ll j=0;j<M;j++) {
    //         cout<<mtrx[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if(check(mid)) 
            lo=mid+1;
        else
            hi=mid-1;
    }

    cout<<ans1+1<<" "<<ans2+1<<endl;

    return 0;
}