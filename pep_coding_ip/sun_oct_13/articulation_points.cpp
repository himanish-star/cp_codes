#include<bits/stdc++.h>

using namespace std;

void findAPUtil(int u,vector<bool> &ap,vector<int> &low,vector<int> &disc,vector<int> &parent,vector<bool> &visited,vector<int> adj[]) {
    static int time_elapsed=0;
    printf("vertex: %d time=%d\n",u,++time_elapsed);
    int children = 0;
    visited[u]=true;
    disc[u] = low[u]= time_elapsed;

    for(int i=0;i<adj[u].size();i++) {
        int v=adj[u][i];
        if(!visited[v]) {
            parent[v]=u;
            children++;
            findAPUtil(v,ap,low,disc,parent,visited,adj);

            low[u] = min(low[u],low[v]);

            if(parent[u]==-1 && children>1) {
                ap[u]=true;
            }

            if(parent[u]!=-1 && low[v]>=disc[u]) {
                printf("error %d %d %d %d\n",parent[u],low[v],low[u],u);
                ap[u]=true;
            }
        } else if(v!=parent[u]) {
            low[u]=min(low[u],disc[v]);
        }
    }
}

void findAP(int V,vector<int> adj[]) {
    vector<bool> visited(V,false);
    vector<int> disc(V,0);
    vector<int> parent(V,-1);
    vector<int> low(V,0);
    vector<bool> ap(V,false);

    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            findAPUtil(i,ap,low,disc,parent,visited,adj);
        }
    }

    cout<<"AP are: ";
    for(int i=0;i<V;i++)
        if(ap[i])
            cout<<i<<" ";
}

int main() {
    int V;
    cin>>V;
    vector<int> adj[V];
    int e;
    cin>>e;

    while(e--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findAP(V,adj);
    cout<<endl;
    return 0;
}