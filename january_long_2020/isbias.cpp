#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n,q;
    cin>>n>>q;

    vector<ll> arr(n);
    for(int i=0;i<n;i++) 
        cin>>arr[i];

    while(q--) {
        int l,r;
        cin>>l>>r;

        l--,r--;
        cout<<l<<","<<r<<endl;

        ll nofi=0,nofd=0,cur=0;
        for(int i=l+1;i<=r;i++) {
            if(arr[i]>arr[i-1] && (i==r || arr[i]>arr[i+1])) {
                nofi++;
            }
        }

        for(int i=l+1;i<=r;i++) {
            if(arr[i]<arr[i-1] && (i==r || arr[i]<arr[i+1])) {
                nofd++;
            }
        }
        
        if(nofi==nofd)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}