#include<bits/stdc++.h>

using namespace std;

#define C 100005

typedef long long ll;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        vector<int> h(C,0);

        vector<vector<int>> rng(n,vector<int> (2,0));
        int max_limit=0;
        for(int i=0;i<n;i++) {
            cin>>rng[i][0]>>rng[i][1];

            max_limit = max(max_limit,rng[i][1]);

            h[rng[i][0]]++;
            h[rng[i][1]+1]--;
        }

        for(int i=1;i<=max_limit;i++) {
            h[i]+=h[i-1];
            // cout<<h[i]<<" ";
        }
        // cout<<endl;


        vector<int> hk(C,0),hkp(C,0);

        ll hkc=0,hkpc=0;

        for(int i=1;i<=max_limit;i++) {
            if(h[i]==k)
                hkc++;
            else if(h[i]==k+1)
                hkpc++;

            hk[i]=hkc;
            hkp[i]=hkpc;
        }

        int ans=0;
        for(int i=0;i<n;i++) {
            int l = rng[i][0];
            int r = rng[i][1];
            ans = max(ans,hk[l-1] + (hk[max_limit]-hk[r]) + (hkp[r]-hkp[l-1]));
        }

        cout<<ans<<endl;
    }
}