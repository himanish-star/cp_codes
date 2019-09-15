#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) {
            return 0;
        }
        
        int steps_remaining=nums[0];
        int jump=1;
        int max_reach=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(i==nums.size()-1) {
                return jump;
            }
            steps_remaining--;
            max_reach=max(max_reach,i+nums[i]);
            
            if(!steps_remaining) {
                jump++;
                
                steps_remaining=max_reach-i;
                
            }
        }
        return jump;
    }
};