#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int number;
        cin>>number;

        int dp[number+1];
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        dp[3]=1;
        for(int i=4;i<=number;i++) {
            int ans=INT_MAX;
            if(i%3==0) {
                ans=min(ans,dp[i/3]);
            }

            if(i%2==0) {
                ans=min(ans,dp[i/2]);
            }

            dp[i]=1+min(ans,dp[i-1]);
        }
        cout<<dp[number]<<endl;
    }
    return 0;
}
