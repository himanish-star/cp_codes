#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int prices[n+1];
    for(int i=1;i<=n;i++) {
        cin>>prices[i];
    }

    int dp[n+1][n+1];

    for(int cl=1;cl<=n;cl++) {
        for(int i=1;i<=n;i++) {
            if(cl==1) {
                dp[i][i]=n*prices[i];
            } else {
                if(i+cl-1<=n) {
                    int year=n-cl+1;
                    dp[i][i+cl-1]=max(year*prices[i]+dp[i+1][i+cl-1],year*prices[i+cl-1]+dp[i][i+cl-2]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
