class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int l=1;l<=n;l++) {
            for(int i=0;i+l-1<n;i++) {
                int j=i+l-1;
                if(l==1) {
                    dp[i][j]=1;
                    continue;
                }
                
                dp[i][j]=1+(dp[i][j-1]);
                vector<int> occr;
                for(int k=i;k<=j;k++) {
                    if(boxes[j]==boxes[k])
                        occr.push_back(k);
                }
                
                if(occr.size()>1) {
                    int ans=occr.size()*occr.size();
                    for(int o=0;o<occr.size()-1;o++) {
                        if(occr[o]+1<=occr[o+1]-1)
                            ans+=dp[occr[o]+1][occr[o+1]-1];
                    }
                    
                    if(i<=occr[0]-1)
                        ans+=dp[i][occr[0]-1];
                    dp[i][j]=max(dp[i][j],ans);
                }
            }
        }
        return dp[0][n-1];
    }
};