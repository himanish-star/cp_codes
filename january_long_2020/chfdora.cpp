#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll eval(int x,int y,vector<vector<int>> &g) {
    int lh=y-1;
    int rh=y+1;
    int uv=x-1;
    int dv=x+1;

    int n=g.size();
    int m=g[0].size();

    ll ans=1;
    while(lh>=0 && uv>=0 && rh<m && dv<n && 
    g[x][lh]==g[x][rh] && 
    g[uv][y]==g[dv][y]) {
        ans++;
        lh--;
        rh++;
        uv--;
        dv++;
    }

    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;

        vector<vector<int>> g(n,vector<int> (m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>g[i][j];
            }
        }

        ll ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans+=eval(i,j,g);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}