#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define vii vector<pii>
#define mp make_pair
#define pb push_back


bool cp(pair<int,int> a,pair<int,int> b) {
    return a.second<b.second;
}

int main() {
    int n;
    cin>>n;

    vii slots;

    for(int i=0;i<n;i++) {
        int c,r;
        cin>>c>>r;
        slots.pb(mp(c-r,c+r));
    }

    sort(slots.begin(),slots.end(),cp);

    int ans=1,end=slots[0].second;

    for(int i=1;i<n;i++) {
        if(slots[i].first>=end) {
            end=slots[i].second;
            ans++;
        }
    }

    cout<<n-ans;

    return 0;
}
