#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int len1,len2;
        cin>>len1>>len2;

        string str1,str2;
        cin>>str1>>str2;

        int dp[len1+1][len2+1];

        for(int i=0;i<=len1;i++) {
            dp[i][0]=i;
        }


        for(int i=0;i<=len2;i++) {
            dp[0][i]=i;
        }

        for(int i=1;i<=len1;i++) {
            for(int j=1;j<=len2;j++) {
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
