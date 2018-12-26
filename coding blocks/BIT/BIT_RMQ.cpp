#include<bits/stdc++.h>

using namespace std;

void update(int *bit,int inc,int pos,int n) {
    while(pos<=n) {
        bit[pos]=max(bit[pos],inc);
        pos+=(pos&(-pos));
    }
    return;
}

int query(int *bit,int pos) {
    int ans=INT_MIN;
    while(pos>0) {
        ans=max(ans,bit[pos]);
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
        cin>>r;
        cout<<query(bit,r)<<endl;
    }
    return 0;
}
