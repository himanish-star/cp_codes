#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct C {
    ll x;
    ll y;
};

bool cp(C a, C b) {
    if(a.x==b.x) {
        return a.y<b.y;
    } else {
        return a.x<b.x;
    }
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<C> co(n);
        for(ll i=0;i<n;i++) {
            ll x,y;
            cin>>x>>y;
            co[i]=C{x,y};
        }

        sort(co.begin(),co.end(),cp);

        ll xc=0,yc=0;
        string res;
        bool notPossible=false;
        for(ll i=0;i<n;i++) {
            while(xc<co[i].x) {
                xc++;
                res.push_back('R');
            }
            while(yc<co[i].y) {
                yc++;
                res.push_back('U');
            }

            if(xc!=co[i].x || yc!=co[i].y) {
                notPossible = true;
                break;
            }
        }

        if(notPossible) {
            cout<<"NO"<<endl;
            continue;
        }

        if(xc==co[co.size()-1].x && yc==co[co.size()-1].y) {
            cout<<"YES"<<endl;
            cout<<res<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}