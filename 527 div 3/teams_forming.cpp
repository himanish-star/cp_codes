#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<n;i+=2) {
        ans += v[i+1] - v[i];
    }
    cout<<ans;
    return 0;
}
