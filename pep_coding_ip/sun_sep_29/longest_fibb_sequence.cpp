#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        
        if(!n) {
            return 0;
        }
        
        if(n==1) {
            return 0;
        }
        
        if(n==2) {
            return 0;
        }
        
        unordered_map<int,int> valuePos;
        for(int i=0;i<n;i++) {
            valuePos.insert(make_pair(A[i],i));
        }
        
        int dp[n][n]={0};
        
        dp[0][0]=0;
        
        dp[1][0]=2;
        dp[1][1]=0;
        
        
        int max_length=INT_MIN;
        for(int i=2;i<n;i++) {
            for(int j=i;j>=0;j--) {
                if(i==j) {
                    dp[i][j]=0;
                } else {
                    if(A[i]-A[j]<A[j] && valuePos.find(A[i]-A[j])!=valuePos.end()) {
                        dp[i][j]=dp[j][valuePos[A[i]-A[j]]]+1;
                    } else {
                        dp[i][j]=2;
                    }
                }
                max_length=max(max_length,dp[i][j]);
            }
        }
        
        if(max_length<3) {
            max_length=0;
        }
        
        return max_length;
    }
};