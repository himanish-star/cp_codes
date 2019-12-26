class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=nums[0],ls=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>=0) {
                ls+=nums[i];
                
                ls=max(nums[i],ls);
                
                ms=max(ms,ls);
            } else {
                ls+=nums[i];
                if(ls<=0)
                    ls=0;
            }
            ms=max(ms,nums[i]);
        }
        
        return ms;
    }
};