class Solution {
    struct Node {
        int p1,p2,p3;
    };
    
    int ssum(vector<int> &csum,int s,int e) {
        if(s==0)
            return csum[e];
        else
            return csum[e]-csum[s-1];
    }
    
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<Node>> dp(n,vector<Node> (4,Node{0,0,0}));
        
        vector<int> csum(n,0);
        csum[0]=nums[0];
        for(int i=1;i<n;i++) {
            csum[i]=csum[i-1]+nums[i];
        }
        
        for(int c=1;c<=3;c++) {
            for(int i=0;i<n;i++) {
                if(c==1) {
                    if(i+1<k) {
                        dp[i][c]=Node{0,0,0};
                    } else if(i+1==k) {
                        dp[i][c]=Node{0,0,0};
                    } else {
                        dp[i][c]=dp[i-1][c];
                        if(ssum(csum,i-k+1,i)>ssum(csum,dp[i][c].p1,dp[i][c].p1+k-1)) {
                            dp[i][c]=Node{i-k+1,0,0};
                        }
                    }
                } else if(c==2) {
                   if(i+1<k*2) {
                        dp[i][c]=Node{0,0,0};
                    } else if(i+1==k*2) {
                        dp[i][c]=Node{0,k,0};
                    } else {
                        dp[i][c]=dp[i-1][c];
                        if(ssum(csum,i-k+1,i)+ssum(csum,dp[i-k][c-1].p1,dp[i-k][c-1].p1+k-1)>ssum(csum,dp[i][c].p2,dp[i][c].p2+k-1)+ssum(csum,dp[i][c].p1,dp[i][c].p1+k-1)) {
                            dp[i][c]=Node{dp[i-k][c-1].p1,i-k+1,0};
                        }
                    }
                } else {
                    if(i+1<k*3) {
                        dp[i][c]=Node{0,0,0};
                    } else if(i+1==k*3) {
                        dp[i][c]=Node{0,k,2*k};
                    } else {
                        dp[i][c]=dp[i-1][c];
                        if(ssum(csum,i-k+1,i)+ssum(csum,dp[i-k][c-1].p1,dp[i-k][c-1].p1+k-1)+ssum(csum,dp[i-k][c-1].p2,dp[i-k][c-1].p2+k-1)>ssum(csum,dp[i][c].p3,dp[i][c].p3+k-1)+ssum(csum,dp[i][c].p2,dp[i][c].p2+k-1)+ssum(csum,dp[i][c].p1,dp[i][c].p1+k-1)) {
                            dp[i][c]=Node{dp[i-k][c-1].p1,dp[i-k][c-1].p2,i-k+1};
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(dp[n-1][3].p1);
        ans.push_back(dp[n-1][3].p2);
        ans.push_back(dp[n-1][3].p3);
        
        return ans;
    }
};