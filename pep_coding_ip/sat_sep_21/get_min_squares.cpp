#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ele=sqrt(n);
        int dp[n+1]={0};


        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++) {
            dp[i]=i;//due to 1*1
            for(int j=2;j<=floor(sqrt(i));j++) {
                int temp=j*j;
                dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
        
        // if(n==6)
        // for(int i=0;i<=ele;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<dp[n]<<endl;
    }
    return 0;
}