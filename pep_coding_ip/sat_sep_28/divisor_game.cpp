#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    map<int,int> dp;
    
    bool dfs(int N) {
        if(N==1) {
            return false;
        }
        
        if(dp.find(N)!=dp.end()) {
            return dp[N]==1;
        }
        
        bool win=false;
        for(int i=1;i<N;i++) {
            if(N%i==0) {
                win = win || !dfs(N-i);
            }
        }
        
        dp[N]=win;
        return win;
    }
    
    bool divisorGame(int N) {
        dp.clear();
        return dfs(N);
    }
};