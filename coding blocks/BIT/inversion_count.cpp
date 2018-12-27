#include <bits/stdc++.h>
using namespace std;

void update(int *bit,int idx,int inc,int n) {
    while(idx<=n) {
        bit[idx]+=inc;
        idx+=(idx&(-idx));
    }
}

int query(int *bit,int idx) {
    int ans=0;
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

        int a[n+1];
        int max_number=INT_MIN;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            max_number=max(max_number,a[i]);
        }
        int ans=0,bit[max_number+1]={0};
        for(int i=n;i>=1;i--) {
            ans+=query(bit,a[i]-1);
            update(bit,a[i],1,max_number);
        }

        cout<<ans<<endl;
    }

}
