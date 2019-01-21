#include <bits/stdc++.h>
using namespace std;

int n,k;

int mod = 1000003;

int dp[101][2][101];

int recur(int i,int prev,int count) {
    if(i==n) {
        if(count==k)
            return 1;
        return 0;
    }

    if(dp[i][prev][count]!=-1)
        return dp[i][prev][count];

    int ans = 0;
    if(prev==1) {
        ans = ans + recur(i+1,1,count+1);
    } else {
        ans = ans + recur(i+1,1,count);
    }

    ans = ans + recur(i+1,0,count);
    ans = ans % mod;
    dp[i][prev][count] = ans;
    return ans;
}

int main() {
    int test_cases;
    cin>>test_cases;

    while(test_cases--) {
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        cout<<recur(1,0,0) + recur(1,1,0)<<endl;
    }
}
