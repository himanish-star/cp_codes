#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        vector<vector<int>> lis;
        
        for(int i=0;i<nums.size();i++) {
            vector<int> row;
            row.push_back(0);
            row.push_back(0);
            lis.push_back(row);
        }
        
        lis[0][0]=1;
        lis[0][1]=1;
        
        int ans=1;
        for(int i=1;i<nums.size();i++) {
            lis[i][0]=1;
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                   if(lis[i][0]<=lis[j][0]+1) {
                       lis[i][0]=lis[j][0]+1;
                   }
                }
            }
            
            for(int j=0;j<i;j++) {
                if(lis[j][0]==lis[i][0]-1 && nums[i]>nums[j]) {
                   lis[i][1]+=lis[j][1];
                }
            }
            
            ans = max(ans,lis[i][0]);
            if(!lis[i][1])
                lis[i][1]=1;
        }
        
        int fans=0;
        for(int i=0;i<nums.size();i++) {
            if(ans==lis[i][0]) {
                fans+=lis[i][1];
            }
        }
        return fans;
    }
};