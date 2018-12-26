#include<bits/stdc++.h>

using namespace std;

void update(int *bit,int inc,int pos,int n) {
    while(pos<=n) {
        bit[pos]+=inc;
        pos+=(pos&(-pos));
    }
    return;
}

int query(int *bit,int pos) {
    int ans=0;
    while(pos>0) {
        ans+=bit[pos];
        pos-=(pos&(-pos));
    }
    return ans;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    int bit[n+1]={0};
    for(int i=0;i<n;i++) {
        cin>>a[i];
        update(bit,a[i],i+1,n);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r;
        cout<<query(bit,r)-query(bit,l-1)<<endl;
    }
    return 0;
}
