class Solution {
    int mod=1000000007;
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long int>> dp(L+1,vector<long long int> (N+1,0));
        
        for(int i=1;i<=L;i++) {
            for(int j=1;j<=N;j++) {
                //element new
                if(j>i)
                    continue;
                if(i==1) {
                    dp[i][j]=N;
                    continue;
                }
                dp[i][j]=((dp[i-1][j-1]*(N-j+1))%mod+(dp[i-1][j]*max(j-K,0))%mod)%mod;
            }
        }
        
        // for(int i=0;i<=L;i++) {
        //     for(int j=0;j<=N;j++) {
        //         //element new
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[L][N];
    }
};