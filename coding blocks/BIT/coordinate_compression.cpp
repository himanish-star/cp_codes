#include <bits/stdc++.h>
using namespace std;

#define ll long long

void update(ll *bit,int idx,int inc,int n) {
    while(idx<=n) {
        bit[idx]+=inc;
        idx+=(idx&(-idx));
    }
}

ll query(ll *bit,int idx) {
    ll ans=0;
    while(idx>0) {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int a[n+1],index=0;
        set<pair<int,int> > st;

        for(int i=1;i<=n;i++) {
            cin>>a[i];
            st.insert(make_pair(a[i],i));
        }

        int idx=0;
        for(set<pair<int,int> >::iterator it=st.begin();it!=st.end();it++) {
            a[(it->second)]=++idx;
        }

        // for(int i=1;i<=n;i++) {
        //     cout<<a[i]<<" ";
        // }

        ll ans=0,bit[n]={0};
        for(int i=n;i>=1;i--) {
            ans+=query(bit,a[i]-1);
            update(bit,a[i],1,n);
        }

        cout<<ans<<endl;
    }

}
