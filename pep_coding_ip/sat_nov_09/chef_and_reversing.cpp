#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

void dijkstra(int s,vector<vector<Edge>> &adj,int N,set<int> &seen,priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> &pq,vector<int> &dist) {
    dist[s]=0;
    pq.push(make_pair(0,s));
    
    while(pq.size()) {
        pair<int,int> top=pq.top();
        pq.pop();

        // cout<<"vselected: "<<top.second<<endl;

        for(int i=0;i<adj[top.second].size();i++) {
            Edge e=adj[top.second][i];
            int v=e.v;
            int w=e.w;

            if(dist[top.second]+w<dist[v]) {
                // cout<<"update: "<<v<<", from: "<<dist[v]<<" --> to: "<<dist[top.second]+w<<endl;
                dist[v]=dist[top.second]+w;
                seen.insert(v);
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

int main() {
    int N,M;
    cin>>N>>M;

    vector<vector<Edge>> adj(N+1);

    for(int i=0;i<M;i++) {
        int src,dest;
        cin>>src>>dest;
        
        if(src==dest)
            continue;

        adj[src].push_back(Edge{src,dest,0});
        adj[dest].push_back(Edge{dest,src,1});
    }

    set<int> seen;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(N+1,INT_MAX);
    
    dijkstra(1,adj,N,seen,pq,dist);
    
    // for(int i=0;i<=N;i++)
    //     cout<<dist[i]<<" ";
    // cout<<endl;
    
    if(dist[N]==INT_MAX)
        cout<<-1<<endl;
    else
    {
        cout<<dist[N]<<endl;
    }
    
    return 0;
}