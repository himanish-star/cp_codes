#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int robUtil(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0) {
            return 0;
        }
        
        if(n==1) {
            return nums[0];
        }
        
        if(n==2) {
            return max(nums[0],nums[1]);
        }
        
        int dp[n]={0};
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++) {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0) {
            return 0;
        }
        
        if(n==1) {
            return nums[0];
        }
        
        if(n==2) {
            return max(nums[0],nums[1]);
        }
        
        vector<int> left,right,middle;
        for(int i=0;i<n;i++) {
            if(i==0) {
                right.push_back(nums[i]);
            } else if(i==n-1) {
                left.push_back(nums[i]);
            } else {
                left.push_back(nums[i]);
                right.push_back(nums[i]);
                middle.push_back(nums[i]);
            }
        }
        
        return max(robUtil(left),robUtil(right));
    }
};