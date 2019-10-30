#include<bits/stdc++.h>

using namespace std;

int find(int parent[],int i) {
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void unionFunc(int parent[],int x,int y) {
    if(find(parent,x)!=find(parent,y))
        parent[x]=y;
}

bool isCyclic(vector<int> adjo[], int V)
{
    int parent[V];
    vector<int> adj[V];
    for(int i=0;i<V;i++)
        parent[i]=-1;
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<adjo[i].size();j++) {
            if(i<=adjo[i][j]) {
                // cout<<i<<" "<<adjo[i][j]<<endl;
                adj[i].push_back(adjo[i][j]);
            }
        }
    }
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<adj[i].size();j++) {
            // cout<<i<<" "<<adj[i][j]<<endl;
            int x=find(parent,i);
            int y=find(parent,adj[i][j]);
            
            if(x==y) {
                // printf("%d[%d]:%d[%d]\n",i,x,adj[i][j],y);
                // cout<<i<<prinx]<<":"<<y<<endl;
                return true;
            } else
                unionFunc(parent,x,y);
        }
    }
    return false;
}