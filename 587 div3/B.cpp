#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin>>n;

    vector<pair<int,int> > v;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(make_pair(x,i+1));
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int cost=1;
    for(int i=1;i<n;i++) {
        cost+=1+(i*v[i].first);
    }

    cout<<cost<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i].second<<" ";
    cout<<endl;

    return 0;
}