class Solution {
public:
    
    bool found;
    double qans;
    map<string,vector<pair<string,double>>> adj;
    map<string,int> visited;
    
    void dfs(string u,string d,double ans) {
        if(u==d) {
            cout<<ans<<endl;
            qans=ans;
            found=true;
            return;
        }
        
        if(visited[u]==1)
            return;
        
        visited[u]=1;
        
        if(adj.find(u)==adj.end())
            return;
        
        for(int i=0;i<adj[u].size();i++) {
            // cout<<adj[u][i].second<<"sd"<<endl;
            dfs(adj[u][i].first,d,ans*(adj[u][i].second));
        }
    }
    
    double solveQuery(vector<string> &query) {
        string s=query[0];
        string d=query[1];
        
        if(adj.find(s)==adj.end()) {
            // cout<<s<<":"<<d<<endl;
            return -1;
        }
        
        double ans=1;
        found=false;
        visited.clear();
        dfs(s,d,ans);
        
        if(!found)
            return -1;
        
        return qans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> qanss;
        adj.clear();
        for(int i=0;i<equations.size();i++) {
            string u=equations[i][0];
            string v=equations[i][1];
            
            double edge=values[i];
            // cout<<u<<"000"<<v<<endl;
            adj[u].push_back(make_pair(v,edge));
            adj[v].push_back(make_pair(u,(1/(double)edge)));
        }
        
        for(int i=0;i<queries.size();i++) {
            qanss.push_back(solveQuery(queries[i]));
        }
        return qanss;
    }
};