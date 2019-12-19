class Solution {
public:
    
    int dfs(vector<vector<int>> &moves,string ring,string key,int ridx,int kidx,vector<vector<int>> &dp) {
        int ans = INT_MAX;
        int n = ring.size();
        
        // cout<<ring[ridx]<<",,"<<key[kidx]<<endl;
        
        if(kidx >= key.size())
            return 0;
        if(ridx >= ring.size())
            return 0;
        
        if(dp[ridx][kidx])
            return dp[ridx][kidx];
        
        for(int i=0;i<moves[key[kidx]-'a'].size();i++) {
            int nidx=moves[key[kidx]-'a'][i];
            int cost=abs(ridx-nidx);
            ans = min(ans,min(cost,n-cost) + dfs(moves,ring,key,nidx,kidx+1,dp));
        }
        return dp[ridx][kidx] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> moves(26);
        for(int i=0;i<ring.size();i++) {
            moves[ring[i]-'a'].push_back(i);
        }
        
        vector<vector<int>> dp(ring.size(),vector<int> (key.size(),0));
        return dfs(moves,ring,key,0,0,dp)+key.size();
    }
};