#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll,pair<ll,ll>> cmap;
ll n,m;

ll cost(ll cnt,vector<vector<ll>> &grid) {

    if(cnt>n*m)
        return 0;
    
    pair<ll,ll> pxy=cmap[cnt];
    ll x=pxy.first;
    ll y=pxy.second;

    // if(x==n && y==m) {
    //     for(int i=1;i<=n;i++) {
    //         for(int j=1;j<=m;j++) {
    //             printf("(%lld,%lld)",grid[i][j],m*(i-1)+j);
    //         }
    //         cout<<endl;
    //     }
    // }

    if(grid[x][y]==(x-1)*m+y)
        return cost(cnt+1,grid);

    // printf("x: %lld, y: %lld to be modified\n",x,y);

    ll temp=grid[x][y];
    grid[x][y]=(x-1)*m+y;
    ll c1=1+cost(cnt+1,grid);
    grid[x][y]=temp;

    ll rotc=0;
    vector<ll> cpy;
    for(int i=1;i<=n;i++)
        cpy.push_back(grid[i][y]);
    
    while(rotc<n && grid[x][y]!=(x-1)*m+y) {
        rotc++;
        temp=grid[1][y];
        for(ll i=1;i<n;i++) {
            grid[i][y]=grid[i+1][y];
        }
        grid[n][y]=temp;
    }

    if(grid[x][y]==(x-1)*m+y) {
        ll c2=rotc+cost(cnt+1,grid);
        for(ll i=0;i<n;i++) {
            grid[i+1][y]=cpy[i];
        }
        return min(c1,c2);
    } else {
        for(ll i=0;i<n;i++) {
            grid[i+1][y]=cpy[i];
        }
        return c1;
    }
}

int main() {
    cin>>n>>m;

    int cnt=1;
    vector<vector<ll>> grid(n+1,vector<ll> (m+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            cmap[m*(i-1)+j]={i,j};
        }
    }

    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         printf("(%lld,%lld)",grid[i][j],m*(i-1)+j);
    //     }
    //     cout<<endl;
    // }

    cout<<cost(1,grid)<<endl;

    return 0;
}