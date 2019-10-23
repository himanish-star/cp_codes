#include<bits/stdc++.h>
using namespace std;

int calMinSqrs(int x,int y) {
    vector<vector<int> > dp(x+1, vector<int> (y+1,0));
    
    if(x==0 || y==0) {
        return 0;
    }

    if(x<0 || y<0) {
        return 0;
    }
    
    for(int i=1;i<=x;i++) {
        for(int j=1;j<=y;j++) {
            dp[i][j]=INT_MAX;
            for(int s=1;s<=min(i,j);s++) {
                dp[i][j]=min(dp[i][j], 1+min(dp[i][j-s]+dp[i-s][s], dp[i-s][j]+dp[s][j-s]));
            }
        }
    }

    // for(int i=0;i<=x;i++) {
    //     for(int j=0;j<=y;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[x][y];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int x,y;
        cin>>x>>y;

        cout<<calMinSqrs(x,y)<<endl;
    }
	return 0;
}