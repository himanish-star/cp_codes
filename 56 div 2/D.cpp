#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 998244353

const int N = int(3e5) + 999;
int p2[N];

bool possible;

vector<vector<int> > edges(N);
vector<int> color;

int countEven,countOdd;

void dfs(int node,int setColor) {
    if(color[node]!=-1) {
        if(color[node]!=setColor)
            possible=false;
        return;
    }
    if(setColor%2) {
        countOdd++;
    } else {
        countEven++;
    }
    color[node]=setColor;
    int newColor=(setColor+1)%2;
    for(int i=0;i<edges[node].size();i++) {
        dfs(edges[node][i],newColor);
    }
    return;
}

int main() {
    int t;
    cin>>t;

    p2[0] = 1;
    for(int i = 1; i < N; ++i)
    	p2[i] = (2 * p2[i - 1]) % mod;

    while(t--) {
        int n,m;
        possible = true;
        cin>>n>>m;

        for(int i=0;i<n;i++) {
            color.push_back(-1);
        }

        for(int i=0;i<m;i++) {
            int u,v;
            cin>>u>>v;
            edges[u-1].push_back(v-1);
            edges[v-1].push_back(u-1);
        }

        int res=1;

        for(int i=0;i<n;i++) {
            if(color[i]==-1) {
                countEven=0;
                countOdd=0;
                dfs(i,0);
                if(!possible) {
                    cout<<0<<endl;
                    break;
                }
                int cur = (p2[countEven] + p2[countOdd]) % mod;
      	        res = (res * 1LL * cur) % mod;
            }
        }

        if(possible) {
            printf("%d\n", res);
        }
        color.clear();
        for(int i=0;i<n;i++) {
            edges[i].clear();cd
        }
    }
    return 0;
}
