#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll A,B;
        cin>>A>>B;

        ll ans=A;

        ll cnt=9,Bcpy=999999999;
        while(B<Bcpy) {
            Bcpy/=10;
            // cout<<Bcpy<<endl;
            cnt--;
        }
        cout<<A*cnt<<endl;
    }
    return 0;
}