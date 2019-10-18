#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod=1000000007;

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<ll> > adj = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3,9,0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {4,2},
        };
        
        ll dp[10][N+1];
        
        for(int i=0;i<10;i++)
            dp[i][1]=1;
        
        for(int i=2;i<=N;i++) {
            for(int j=0;j<=9;j++) {
                dp[j][i]=0;
                
                for(int k=0;k<adj[j].size();k++) {
                    dp[j][i]+=dp[adj[j][k]][i-1];
                    dp[j][i]%=mod;
                }
            }
        }
        
        
        ll ans=0;
        for(int i=0;i<10;i++) {
            ans+=dp[i][N];
            ans%=mod;
        }
        
        return ans;
    }
};