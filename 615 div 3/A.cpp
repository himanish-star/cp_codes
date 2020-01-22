#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll a,b,c,n;
        cin>>a>>b>>c>>n;

        if((a+b+c+n)%3!=0) {
            cout<<"NO"<<endl;
            continue;
        }

        ll k=(a+b+c+n)/3;

        if(k>=a && k>=b && k>=c) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}