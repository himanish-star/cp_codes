#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        string ans;
        for(int i=0;i<k;i++) {
            for(int j=0;j<n/k;j++) {
            ans.push_back('a'+i);
            }
        }

        for(int i=0;i<n%k;i++) {
            ans.push_back('a'+i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
