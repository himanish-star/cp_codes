#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int> > pairs;
    for(int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        pairs.push_back(make_pair(l,r));
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++) {
        if(k>=pairs[i].first && k<=pairs[i].second) {
            cout<<n-i;
            break;
        }
    }
    return 0;
}
