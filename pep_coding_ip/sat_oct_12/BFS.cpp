#include<bits/stdc++.h>

using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int> qu;
    qu.push(s);
    
    while(qu.size()) {
        int level=qu.size();
        
        while(level--) {
            int e=qu.front();
            qu.pop();
            if(vis[e]==true) {
                continue;
            }
            vis[e]=true;
            cout<<e<<" ";
            for(int i=0;i<adj[e].size();i++)
                qu.push(adj[e][i]);
        }
    }
}