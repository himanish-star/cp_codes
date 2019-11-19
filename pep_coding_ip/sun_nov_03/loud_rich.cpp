class Solution {
private:
    struct Node {
        int idx;
        int quiet;        
        int ansIdx;
        int ansQuiet;
        vector<int> children;
    };
    
    void dfs(int s,Node nodes[],vector<int> &visited) {
        if(visited[s])
            return;
        visited[s]=1;
        
        for(int i=0;i<nodes[s].children.size();i++) {
            int cIdx=nodes[s].children[i];
            if(!visited[cIdx])
                dfs(cIdx,nodes,visited);
            if(nodes[s].ansQuiet>nodes[cIdx].ansQuiet) {
                nodes[s].ansIdx=nodes[cIdx].ansIdx;
                nodes[s].ansQuiet=nodes[cIdx].ansQuiet;
            }
        }
    }
    
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        Node nodes[quiet.size()];
        
        vector<int> result;
        for(int i=0;i<quiet.size();i++) {
            vector<int> children;
            nodes[i]=Node{i,quiet[i],i,quiet[i],children};
        }
        
        for(int i=0;i<richer.size();i++) {
            int u=richer[i][1];
            int v=richer[i][0];
            
            nodes[u].children.push_back(v);
        }
        
        vector<int> visited(quiet.size(),0);
        for(int i=0;i<quiet.size();i++) {
            dfs(i,nodes,visited);
            result.push_back(nodes[i].ansIdx);
        }
        
        return result;
    }
};