#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,string s3,vector<vector<vector<int>>> &dp) {
    for(int i=1;i<=s1.size();i++) {
        for(int j=1;j<=s2.size();j++) {
            for(int k=1;k<=s3.size();k++) {
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }

    return dp[s1.size()][s2.size()][s3.size()];
}

int main() {
	int ts;
    cin>> ts;

    while (ts--)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;

        string s1,s2,s3;
        cin>>s1>>s2>>s3;

        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1,0)));
        cout<<lcs(s1,s2,s3,dp)<<endl;
    }
    
	return 0;
}