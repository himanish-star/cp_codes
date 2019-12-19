class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            int num=nums[i];
            if(num>0) {
                minp = minp * num;
                maxp = max(num,maxp * num);
            } else {
                int tp=maxp;
                maxp = max(num,max(minp * num,maxp * num));
                minp = min(num,min(minp * num,tp * num));
            }
            ans=max(ans,maxp);
        }
        
        return ans;
    }
};