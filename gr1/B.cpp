#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n,m,k;
    cin>>n>>m>>k;

    ll diff[n-1];
    ll lastv;
    cin>>lastv;
    for(int i=0;i<n-1;i++) {
        ll cur;
        cin>>cur;
        diff[i]=cur-lastv;
        lastv=cur;
        // cout<<cur<<" ";
    }
    if(k>=n) {
        cout<<n<<endl;
        return 0;
    }
    sort(diff,diff+n-1);
    // for(int i=0;i<n-1;i++) {
    //     cout<<diff[i]<<" ";
    // }
    // cout<<endl;
    ll ans=0;
    for(int i=0;i<n-k;i++) {
        ans+=diff[i];
    }
    ans+=1;
    cout<<ans+k-1<<endl;
    return 0;
}
