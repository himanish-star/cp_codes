void dfs(int u,stack<int> &st,vector<int> &visited,vector<int> adj[]) {
    if(visited[u])
        return;
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
        dfs(adj[u][i],st,visited,adj);
    st.push(u);
}

void normalTravel(int u,vector<int> &visited,vector<int> adj[]) {
    if(visited[u])
        return;
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
        normalTravel(adj[u][i],visited,adj);
}
 
int findMother(int V, vector<int> adj[]) 
{ 
    stack<int> st;
    vector<int> visited(V,0);
    
    for(int i=0;i<V;i++) {
        if(!visited[i])
            dfs(i,st,visited,adj);
    }
    int motherVertex=st.top();
    for(int i=0;i<V;i++)
        visited[i]=0;
    normalTravel(motherVertex,visited,adj);
    int noOfNodesVis=0;
    for(int i=0;i<V;i++)
        noOfNodesVis+=visited[i];
    if(noOfNodesVis==V)
        return motherVertex;
    else
        return -1;
} 