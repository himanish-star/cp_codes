#include <bits/stdc++.h>
using namespace std;

bool cp(pair<string,int> a,pair<string,int> b) {
    return a.second<b.second;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<pair<string,int> > slot(n);

        for(int i=0;i<n;i++) {
            cin>>slot[i].first>>slot[i].second;
        }

        sort(slot.begin(),slot.end(),cp);
        long long ans=0;
        for(int i=0;i<n;i++) {
            ans+=abs(i+1-slot[i].second);
        }
        cout<<ans<<endl;
    }
}
