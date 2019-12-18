class Solution {
public:
    int numTilings(int N) {
        int mod=1000000007;
        vector<vector<int>> dp(N+1, vector<int> (3,0));
        
        dp[1][0]=1;
        dp[0][0]=1;
        for(int i=2;i<=N;i++) {
            dp[i][0]=((dp[i-2][0]+dp[i-1][0])%mod+(dp[i-1][1]+dp[i-1][2])%mod)%mod;
            dp[i][1]=(dp[i-2][0]+dp[i-1][2])%mod;
            dp[i][2]=(dp[i-2][0]+dp[i-1][1])%mod;
        }
        
        return (int)dp[N][0];
    }
};