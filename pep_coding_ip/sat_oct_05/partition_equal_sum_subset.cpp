class Solution {
public:
    bool dfs(vector<vector<int>> &dp,vector<int> &nums,int idx,int ts) {
        if(idx<0) {
            if(ts==0)
                return true;
            return false;
        }
        
        if(ts<0)
            return false;
        
        if(dp[idx][ts]!=-1)
            return dp[idx][ts]==1;
        
        if(dfs(dp,nums,idx-1,ts-nums[idx]) || dfs(dp,nums,idx-1,ts)) {
            dp[idx][ts]=1;
        } else {
            dp[idx][ts]=0;
        }
        
        return dp[idx][ts]==1;
    }
    
    bool canPartition(vector<int>& nums) {
        int ts=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++) {
            ts+=nums[i];
        }
        
        if(ts%2)
            return false;
        
        ts/=2;
        
        vector<vector<int>> dp(n,vector<int> (ts+1,-1));
        return dfs(dp,nums,n-1,ts);
    }
};