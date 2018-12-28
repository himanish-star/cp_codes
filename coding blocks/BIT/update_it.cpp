#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void update(ll *bit,int idx,int inc,int n) {
    while(idx<=n) {
        bit[idx]+=inc;
        idx+=(idx&(-idx));
    }
}

ll query(ll *bit,int idx) {
    ll sum=0;
    while(idx>0) {
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--) {
        int n,u;
        cin>>n>>u;
        ll bit[n+1]={0};
        while(u--) {
            int l,r,val;
            cin>>l>>r>>val;
            l++,r++;
            update(bit,l,val,n),update(bit,r+1,-val,n);
        }
        int q;
        cin>>q;
        while(q--) {
            int addr;
            cin>>addr;
            addr++;
            cout<<query(bit,addr)<<endl;
        }
    }
    return 0;
}
