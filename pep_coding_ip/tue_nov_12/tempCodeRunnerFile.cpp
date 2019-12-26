#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        int arr[n*k];
        for(int i=0;i<n*k;i++) {
            cin>>arr[i];
        }

        int ls=arr[0],ms=arr[0];
        for(int i=1;i<n*k;i++) {
            if(arr[i]>=0) {
                ls+=arr[i];
                ms=max(ms,ls);
            } else {
                ms=max(arr[i],ms);
                ls=0;
            }
        }
    }
    return 0;
}