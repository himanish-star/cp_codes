#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    long long n;
    cin>>n;

    long long a[n];
    a[0]=0;
    cin>>a[n-1];
    ll l=0,r=a[n-1];

    for(ll i=1;i<n/2;i++) {
        ll temp;
        cin>>temp;
        a[i]=max(l,temp-r);
        a[n-1-i]=temp-a[i];
        l=a[i];
        r=a[n-i-1];
    }
    // for(ll i=0;i<n/2;i++) {
    //     long long temp;
    //     cin>>temp;
    //     if(temp%2) {
    //         a[i]=temp/2;
    //         a[n-i-1]=(temp/2)+1;
    //     } else {
    //         a[i]=temp/2;
    //         a[n-i-1]=temp/2;
    //     }
    // }

    // for(ll i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;

    // for(ll i=0;i<n-1;i++) {
    //     if(a[i]>a[i+1]) {
    //         if(i>=n/2) {
    //             long long diff = a[i]-a[i+1];
    //             long long avail = a[n-i-2];
    //             if(avail>=diff) {
    //                 a[i+1]+=diff;
    //                 a[n-i-2]-=diff;
    //             } else {
    //                 a[i+1]+=avail;
    //                 a[n-i-2]=0;
    //             }
    //         } else {
    //             long long diff = a[i]-a[i+1];
    //             a[i]-=diff;
    //             a[n-1-i]+=diff;
    //         }
    //     }
    // }

    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
