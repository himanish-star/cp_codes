class Solution {
    bool bfs(int src,map<int,vector<int>> &adj,vector<int> &color) {
        queue<int> qu;
        qu.push(src);
        
        int c=1;
        while(qu.size()) {
            int count=qu.size();
            while(count--) {
                int e=qu.front();
                qu.pop();
                color[e]=c;
                for(int i=0;i<adj[e].size();i++) {
                    int nxt=adj[e][i];
                    if(!color[nxt])
                        qu.push(nxt);
                    else {
                        if(c==color[nxt])
                            return false;
                    }
                }
            }
            if(c==1)
                c=2;
            else
                c=1;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(!dislikes.size())
            return true;
        map<int,vector<int>> adj;
        vector<int> color(N,0);
        
        for(int i=0;i<dislikes.size();i++) {
            int u=dislikes[i][0]-1;
            int v=dislikes[i][1]-1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool ans=true;
        for(int i=0;i<N;i++) {
            if(!color[i])
                ans=ans && bfs(i,adj,color);
            if(!ans)
                return ans;
        }
        return ans;
    }
};