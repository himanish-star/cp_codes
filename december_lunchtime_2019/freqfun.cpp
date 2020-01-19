#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int G[n+1];
        int A[n];

        for(int i=0;i<n;i++)
            cin>>A[i];

        for(int i=0;i<=n;i++) {
            cin>>G[i];
        }

        // samples 
        // A = -1 0 -1
        // G = 0 3 0 0
        // 0 -> 0
        // 1 -> 3
        // 2 -> 0
        // 3 -> 0

        map<int,int> avail;
        int e=0,ptr;

        for(int i=0;i<n;i++) {
            if(A[i]!=-1) {

            } else {

            }
        }
    }

    return 0;
}