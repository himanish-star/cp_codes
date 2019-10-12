#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int len=s.size();
        int dp[len]={0};

        for(int i=0;i<len;i++) {
            if(s[i]=='b') {
                for(int j=0;j<i;j++) {
                    if(s[j]=='a')
                        dp[i]++;
                }
            } else if(s[i]=='c') {
                for(int j=0;j<i;j++) {
                    if(s[j]=='b')
                        dp[i]+=dp[j]; 
                }
            }
        }

        int ans=0;
        for(int i=0;i<len;i++) {
            if(s[i]=='c')
                ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}