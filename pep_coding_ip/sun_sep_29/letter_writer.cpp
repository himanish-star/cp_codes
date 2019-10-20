#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int dp[n+1]={0};
        dp[0]=0;

        for(int i=1;i<=n;i++) {
            dp[i]=-1;
            if(i-10>=0 && dp[i-10]!=-1)
                dp[i]=1+dp[i-10];
            if(i-12>=0 && dp[i-12]!=-1) {
                if(dp[i]==-1)
                    dp[i]=1+dp[i-12];
                else
                    dp[i]=min(dp[i],1+dp[i-12]);
            }
        }

        // cout<<endl;
        // for(int i=0;i<=n;i++)
        //     printf("%d[%d] ",dp[i],i);
        // cout<<endl;

        cout<<dp[n]<<endl;
    }
	return 0;
}