#include<bits/stdc++.h>

using namespace std;

bool cp(pair<int,int> a,pair<int,int> b) {
    return a.second<b.second;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<pair<int,int> > slots(n);
        for(int i=0;i<n;i++) {
            cin>>slots[i].first>>slots[i].second;
        }

        sort(slots.begin(),slots.end(),cp);
        int ans=1,end=slots[0].second;
        for(int i=1;i<n;i++) {
            if(slots[i].first>=end) {
                ans++;
                end=slots[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
