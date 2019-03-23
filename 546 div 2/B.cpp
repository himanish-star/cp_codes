#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;

    int arr[n+1], cct=0;
    for(int i=1;i<=n/2;i++) {
        arr[i]=cct++;
    }
    int nextStart;
    if(n%2) {
        arr[n/2+1]=cct;
        nextStart=n/2+2;
    } else {
        nextStart=n/2+1;
    }
    for(int i=nextStart;i<=n;i++) {
        arr[i]=--cct;
    }
    cout<<3*n+arr[k]<<endl;
}
