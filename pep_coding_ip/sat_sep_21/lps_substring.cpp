#include<bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    int s;
    int e;
};

int main()
 {
	//code
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int n=s.size();
        vector<vector<Node>> dp(n,vector<Node> (n,Node{1,0,0}));

        for(int l=1;l<=n;l++) {
            for(int i=0;i+l-1<n;i++) {
                int j=i+l-1;
                if(l==1) {
                    dp[i][j]=Node{1,i,j};
                    continue;
                } else if(l==2) {
                    if(s[i]==s[j]) {
                        dp[i][j]=Node{2,i,j};
                    } else {
                        dp[i][j]=Node{1,i,i};
                    }
                } else {
                    if(s[i]==s[j] && dp[i+1][j-1].v==l-2) {
                        dp[i][j]=Node{l,i,j};
                    } else {
                        dp[i][j]=dp[i+1][j-1];
                        
                        if(dp[i+1][j].v>dp[i][j].v) {
                            dp[i][j]=dp[i+1][j];
                        }
                        
                        if(dp[i][j-1].v>dp[i][j].v) {
                            dp[i][j]=dp[i][j-1];
                        }
                    }
                }
            }
        }

        int dres=dp[0][n-1].v;
        
        vector<string> res;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j].v==dres) {
                    res.push_back(s.substr(dp[i][j].s,dp[i][j].e-dp[i][j].s+1));
                }
            }
        }
        
        // sort(res.begin(),res.end());
        cout<<res[0]<<endl;

    }
	return 0;
}