class Solution {
public:
    
    vector<string> fresult;
    int n;
    bool found;
    void dfs(string src,map<string,vector<string>> &adj,vector<string> result) {
        
        int tkts_remain=adj[src].size();
        // cout<<"arrived at "<<src<<" tkts: "<<tkts_remain<<endl;
        if(!tkts_remain || found) {
            if(n==result.size() && !found) {
                fresult = result;
                found=true;
            }
            return;
        }
        
        for(int i=0;i<tkts_remain;i++) {
            vector<string> temp=adj[src];
            string dest=adj[src][i];
            adj[src].erase(adj[src].begin()+i);
            
            result.push_back(dest);
            dfs(dest,adj,result);

            result.pop_back();
            adj[src] = temp;
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>> adj;
        
        vector<string> result;
        if(!tickets.size())
            return result;
        
        for(int i=0;i<tickets.size();i++) {
            string src=tickets[i][0];
            string dest=tickets[i][1];
            
            if(adj.find(src)==adj.end()) {
                vector<string> v;
                v.push_back(dest);
                adj[src]=v;
            } else {
                adj[src].push_back(dest);
                sort(adj[src].begin(),adj[src].end());
            }
        }
        
        result.push_back(string("JFK"));
        n=tickets.size()+1;
        found=false;
        dfs("JFK",adj,result);
        return fresult;
    }
};