#include<bits/stdc++.h>

using namespace std;

int dfs(int s,vector<int> adj[],vector<int> adjRev[],vector<int> &dp,int N,vector<int> &vis) {
    if(dp[s])
        return dp[s];
    if(s==N-1)
        return dp[s]=0;

    vis[s]=1;
    dp[s]=INT_MAX;
    for(int i=0;i<adj[s].size();i++) {
        if(!vis[adj[s][i]]) {
            int updVal=dfs(adj[s][i],adj,adjRev,dp,N,vis);
            if(updVal!=INT_MAX)
                dp[s]=min(dp[s],updVal);
        }
    }

    for(int i=0;i<adjRev[s].size();i++) {
        if(!vis[adjRev[s][i]]) {
            int updVal=dfs(adjRev[s][i],adj,adjRev,dp,N,vis);
            if(updVal!=INT_MAX)
                dp[s]=min(dp[s],1+updVal);
        }
    }
    return dp[s];
}

int main() {
    int N,M;
    cin>>N>>M;

    vector<int> adj[N],adjRev[N];
    for(int i=0;i<M;i++) {
        int src,dest;
        cin>>src>>dest;
        src--,dest--;
        adj[src].push_back(dest);
        adjRev[dest].push_back(src);
    }

    vector<int> dp(N,0);
    vector<int> vis(N,0);
    int ans=dfs(0,adj,adjRev,dp,N,vis);
    if(ans==INT_MAX)
        ans=-1;
    cout<<ans<<endl;
    // for(int i=0;i<N;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    return 0;
}