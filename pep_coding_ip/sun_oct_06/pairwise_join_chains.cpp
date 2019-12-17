class Solution {
private:
    bool cp(vector<int> a,vector<int> b) {
        return a[1]<b[0];
    }    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int max_len=0;
        
        vector<int> dp(n,0);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++) {
            if(pairs[i][0]<pairs[i][1]) {
                dp[i]=1;
                for(int j=0;j<i;j++) {
                    if(pairs[i][0]>pairs[j][1])
                        dp[i]=max(dp[i],1+dp[j]);
                }
            }
            max_len=max(max_len,dp[i]);
        }
            
        return max_len;
    }
};