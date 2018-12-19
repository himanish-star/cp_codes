#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans=0;
        if(n%2) {
            ans = (n-3)/2 + 1;
        } else {
            ans = n/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
