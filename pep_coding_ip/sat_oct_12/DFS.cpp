#include<bits/stdc++.h>

using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    if(vis[s]==true)
        return;
    
    vis[s]=true;
    cout<<s<<" ";
    for(int i=0;i<g[s].size();i++)
        dfs(g[s][i],g,vis);
    // vis[s]=false;
}