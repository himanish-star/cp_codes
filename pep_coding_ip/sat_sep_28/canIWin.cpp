#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0) {
            //player one wins
            return true;
        }
        
        if(maxChoosableInteger*(maxChoosableInteger+1)*0.5<desiredTotal) {
            //sum never achievable
            return false;
        }
        
        if(maxChoosableInteger>=desiredTotal) {
            //player one wins
            return true;
        }
        
        vector<int> dp(1<<maxChoosableInteger);
        
        return dfs(dp,desiredTotal,0,maxChoosableInteger);
    }
    
    bool dfs(vector<int>& dp,int target,ll state,int max) {
        if(target<=0) {
            return false;
        }
        
        if(dp[state]!=0) {
            return dp[state]==1;
        }
        
        bool win=false;
        for(int i=0;i<max;i++) {
            if((state & (1<<i))==0) {
                //number not chosen yet
                win = win || !dfs(dp,target-i-1,state ^ (1<<i),max);
            }
        }
        
        dp[state] = win ? 1:-1;
        return win;
    }
};
