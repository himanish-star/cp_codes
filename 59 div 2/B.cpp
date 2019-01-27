#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin>>n;

    while(n--) {
        ll k;
        int x;
        cin>>k>>x;

        ll temp=9*k;
        cout<<temp-9+x<<endl;
    }
}
