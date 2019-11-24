class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(A.size(),vector<int> (A.size(),0));
        
        for(int l=3;l<=A.size();l++) {
            for(int i=0;i+l-1<A.size();i++) {
                int j=i+l-1;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++) {
                    dp[i][j]=min(dp[i][j],A[i]*A[j]*A[k]+dp[i][k]+dp[k][j]);
                }
            }
        }
        
        
        return dp[0][A.size()-1];
    }
};