#include<bits/stdc++.h>

using namespace std;

int* topoSort(int V, vector<int> adj[])
{
    int *result = new int[V];
    int it=0;
    
    vector<int> indeg(V,0);
    for(int i=0;i<V;i++) {
        for(int j=0;j<adj[i].size();j++)
            indeg[adj[i][j]]++;
    }
    
    queue<int> qu;
    for(int i=0;i<V;i++) {
        if(indeg[i]==0)
            qu.push(i);
    }
    
    while(qu.size()) {
        int level=qu.size();
        while(level--) {
            int ele=qu.front();
            qu.pop();
            result[it++]=ele;
            for(int i=0;i<adj[ele].size();i++) {
                if(--indeg[adj[ele][i]]==0)
                    qu.push(adj[ele][i]);
            }
        }
    }
    return result;
}