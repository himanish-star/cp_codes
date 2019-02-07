#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int q;
    cin>>q;
    while(q--) {
        ll num;
        cin>>num;
        vector<int> pos;
        ll temp=num;
        int i=0;
        int counts=0;
        while(temp) {
            counts++;
            if(temp&1) {

            } else {
                pos.push_back(i);
            }
            i++;
            temp >>= 1;
        }
        if(pos.size()) {
            ll ans=0;
            for(int i=0;i<counts;i++) {
                ans += pow(2,i);
            }
            cout<<ans<<endl;
        } else {
            ll ans=0;
            for(int i=1;i<counts;i+=2) {
                ans += pow(2,i);
            }
            if((ans)%(num-ans)) {
                cout<<1<<endl;
            } else {
                cout<<num-ans<<endl;
            }
        }
    }
    return 0;
}
