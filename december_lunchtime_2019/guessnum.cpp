#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll A,M;
        cin>>A>>M;

        vector<ll> div;

        for(ll i=1;i<sqrt(M)+1;i++) {
            if(M%i==0) {
                div.push_back(i);
                div.push_back(M/i);
            }
        }

        vector<ll> res;
        for(ll i=0;i<div.size();i++) {
            // printf("div --> %d, N --> %d\n",div[i],(M-div[i])/A);
            if((M-div[i])%A==0 && div[i] <= (M-div[i])/A && ((M-div[i])/A)%div[i]==0)
                res.push_back((M-div[i])/A);
        }

        sort(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(ll i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}