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
    int t;
    cin>>t;

    while(t--) {
        int N;
    cin>>N;

    vector<vector<Edge>> adj(N+1);

    for(int i=1;i<=N;i++) {
        int src=i,dest;
        
        if(src*3<=N) {
            dest=src*3;
            adj[src].push_back(Edge{src,dest,1});
        }

        if(src+1<=N) {
            dest=src+1;
            adj[src].push_back(Edge{src,dest,1});
        }
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
    }
    
    return 0;
}