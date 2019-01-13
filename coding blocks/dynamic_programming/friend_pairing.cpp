#include<bits/stdc++.h>


using namespace std;



typedef long long ll;

ll mod = 1000000007;

int main() {
    int test_cases;
    cin>>test_cases;

    while(test_cases--) {
        int n;
        cin>>n;

        ll dp[n+1]={0};

        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++) {
            dp[i]=((dp[i-1])+((i-1)*dp[i-2])%mod)%mod;
            if(dp[i]<0)
                dp[i]+=mod;
        }
        cout<<dp[n]<<endl;
    }
}
