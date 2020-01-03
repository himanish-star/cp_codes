#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll A;
        cin>>A;

        ll S=((ll)(pow(10,n))*2)+A;
        cout<<S<<endl;
        fflush(stdout);

        ll B;
        cin>>B;

        cout<<(ll)(pow(10,n))-B<<endl;
        fflush(stdout);

        ll C;
        cin>>C;

        cout<<(ll)(pow(10,n))-C<<endl;
        fflush(stdout);

        ll res;
        cin>>res;

        if(res==-1)
            break;
    }
    return 0;
}