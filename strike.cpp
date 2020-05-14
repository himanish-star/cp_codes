#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

bool escapeFlag;

int dfs(int present,vector<vector<Edge>> &adj,vector<int> &vis,int end,unordered_map<int,int> &smap, Edge &be) {
    if(present==end) {
        escapeFlag=true;
        return 0;
    }
    if(smap[present]==1)
        return 0;
    int best_ans=INT_MAX;
    vis[present]=1;
    for(int i=0;i<adj[present].size();i++) {
        if(vis[adj[present][i].v] || (be.u==present && be.v==adj[present][i].v) || (be.v==present && be.u==adj[present][i].v))
            continue;
        int lpans=dfs(adj[present][i].v,adj,vis,end,smap,be);
        if(lpans==-1)
            continue;
        best_ans=min(best_ans,adj[present][i].w+lpans);
    }
    vis[present]=0;
    if(best_ans==INT_MAX)
        best_ans=-1;
    return best_ans;
}

void canEscape(int present,vector<vector<Edge>> &adj,vector<int> &vis,int end,unordered_map<int,int> &smap, Edge &be) {
    if(present==end) {
        escapeFlag=true;
        return;
    }
    // if(smap[present]==1)
    //     return 0;
    vis[present]=1;
    for(int i=0;i<adj[present].size();i++) {
        if(vis[adj[present][i].v] || (be.u==present && be.v==adj[present][i].v) || (be.v==present && be.u==adj[present][i].v))
            continue;
        canEscape(adj[present][i].v,adj,vis,end,smap,be);
    }
    vis[present]=0;
    return;
}

int main() {
    int N,S,Q,E;
    cin>>N>>S>>Q>>E;

    vector<Edge> e(N-1); 
    vector<vector<Edge>> adj(N+1);
    for(int i=0;i<N-1;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(Edge{u,v,w});
        adj[v].push_back(Edge{v,u,w});
        e[i]=Edge({u,v,w});
    }

    unordered_map<int,int> smap;
    for(int i=0;i<S;i++) {
        int bn;
        cin>>bn;
        smap[bn]=1;
    }

    while(Q--) {
        int block,present;
        cin>>block>>present;

        queue<int> qu;
        qu.push(present);
        vector<int> vis(N+1,0);
        escapeFlag=false;

        canEscape(present,adj,vis,E,smap,e[block-1]);
        if(escapeFlag) {
            cout<<"escaped"<<endl;
            continue;    
        }
        
        int ans = dfs(present,adj,vis,E,smap,e[block-1]);
        // cout<<"block "<<e[block-1].u<<", "<<e[block-1].v<<endl;
        if(escapeFlag)
            cout<<"escaped"<<endl;
        else if(ans==-1){
            cout<<"oo"<<endl;
        } else {
            cout<<ans<<endl;
        }
    }

    return 0;
}