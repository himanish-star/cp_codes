#include<bits/stdc++.h>

using namespace std;

void dfsUtil(int u,stack<int> &st,vector<int> &visited,vector<int> adj[]) {
    if(visited[u])
        return;
    
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++) {
        dfsUtil(adj[u][i],st,visited,adj);
    }
    st.push(u);
}

void dfs(int u,vector<int> adj[],vector<int> &visited) {
    if(visited[u])
        return;
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
        dfs(adj[u][i],adj,visited);
}

int kosaraju(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> visited(V,0);
    for(int i=0;i<V;i++) {
        if(!visited[i])
            dfsUtil(i,st,visited,adj);
    }
    
    vector<int> newAdj[V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<adj[i].size();j++) {
            // printf("[%d -> %d]",adj[i][j],i);
            newAdj[adj[i][j]].push_back(i);
        }
    }
    
    for(int i=0;i<V;i++) visited[i]=0;
    int ans=0;
    while(st.size()) {
        int ele=st.top();
        st.pop();
        
        if(visited[ele])
            continue;
        ans++;
        // cout<<ele<<endl;
        dfs(ele,newAdj,visited);
    }
    return ans;
}