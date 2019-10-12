#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int min_cost(int arr[],int n) {
    int dp[n][n]={0};

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dp[i][j]=0;
        }
    }

    if(n<3) {
        return 0;
    }

    if(n==3) {
        return arr[0]*arr[1]*arr[2];
    }

    for(int l=3;l<=n;l++) {
        for(int i=0;i+l-1<n;i++) {
            int j=i+l-1;

            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++) {
                int sub_cost=dp[i][k]+(arr[i]*arr[k]*arr[j])+dp[k][j];
                dp[i][j]=min(dp[i][j],sub_cost);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        int array[n];
        for(int i=0;i<n;i++) {
            cin>>array[i];
        }

        cout<<min_cost(array, n)<<endl;
    }
    return 0;
}