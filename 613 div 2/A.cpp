#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll pl=0,pr=0;
    for(ll i=0;i<n;i++) {
        if(s[i]=='L')
            pl++;
        else
        {
            pr++;
        }
    }
    cout<<pr+pl+1<<endl;
}