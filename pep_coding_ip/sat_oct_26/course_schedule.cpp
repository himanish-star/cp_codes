class Solution {
public:
    
    bool isCycle;
    
    void dfs(int u,vector<int> adj[],vector<int> &visited) {
        if(visited[u]) {
            isCycle=true;
            return;
        }
        visited[u]=1;
        for(int i=0;i<adj[u].size();i++)
            dfs(adj[u][i],adj,visited);
        visited[u]=0;
    }
    
    bool detectCycle(int V,vector<int> adj[]) {
        vector<int> visited(V,0);
        isCycle=false;
        for(int i=0;i<V;i++)
            if(!visited[i] && !isCycle)
                dfs(i,adj,visited);
        return isCycle;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        if(!prerequisites.size()) {
            for(int i=0;i<numCourses;i++)
                order.push_back(i);
            return order;
        }
        
        map<int,int> redMap;
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        for(int i=0;i<prerequisites.size();i++) {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
                
            indeg[v]++;
                
            // cout<<u<<"::"<<v<<endl;
            adj[u].push_back(v);
                
            redMap[u]=v;
            if(redMap.find(v)!=redMap.end() && redMap[v]==u) {
                return order;
            }
        }
        
        // cout<<"endl"<<endl;
        if(detectCycle(numCourses,adj))
            return order;
        
        queue<int> qu;
        for(int i=0;i<numCourses;i++) {
            if(indeg[i]==0)
                qu.push(i);
        }
        
        while(qu.size()) {
            int lc=qu.size();
            while(lc--) {
                int ele=qu.front();
                qu.pop();
                order.push_back(ele);
                
                for(int i=0;i<adj[ele].size();i++) {
                    if(--indeg[adj[ele][i]]==0) {
                        qu.push(adj[ele][i]);
                    }
                }
            }
        }
        
        return order;
    }
};