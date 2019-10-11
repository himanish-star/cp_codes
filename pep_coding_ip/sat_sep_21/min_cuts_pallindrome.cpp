#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;


        int len=s.size();
        //first let's compute the substrings that are pallindromic
        bool dp[len][len];

        for(int l=1;l<=len;l++) {
            for(int i=0;i+l-1<len;i++) {
                int j=i+l-1;

                if(l==1) {
                    dp[i][j]=true;
                    continue;
                }

                if(l==2) {
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                    continue;
                }

                if(s[i]==s[j]) {
                    dp[i][j]=dp[i+1][j-1];
                } else {
                    dp[i][j]=false;
                }
            }
        }

        int dp2[len][len];

        for(int i=0;i<len;i++) {
            if(dp[0][i]) {
                dp2[0][i]=0;//string already a pallindrome
            } else {
                dp2[0][i]=INT_MAX;
                for(int j=0;j<=i;j++) {
                    if(dp[j][i]) {
                        dp2[0][i]=min(dp2[0][i],dp2[0][j-1]+1);
                    }
                }
            }
        }

        cout<<dp2[0][len-1]<<endl;
    }
    return 0;
}