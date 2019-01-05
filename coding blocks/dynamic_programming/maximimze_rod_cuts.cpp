#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int len,x,y,z;
        cin>>len>>x>>y>>z;

        int dp[len+1]={0};

        if(x<=len)
        dp[x]=1;
        if(y<=len)
        dp[y]=1;
        if(z<=len)
        dp[z]=1;

        for(int i=1;i<=len;i++) {
            int ans=0;
            if(i-x>0) {
                ans=max(ans,dp[i-x]);
            }
            if(i-y>0) {
                ans=max(ans,dp[i-y]);
            }
            if(i-z>0) {
                ans=max(ans,dp[i-z]);
            }
            if(ans)
                dp[i]=1+ans;
        }
        cout<<dp[len]<<endl;
    }
    return 0;
}
