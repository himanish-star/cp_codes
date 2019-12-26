class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        int ln=nums[0];
        
        int nl=1,idx=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=ln) {
                ln=nums[i];
                nl++;
                nums[idx++]=nums[i];
            }
        }
            
        return nl;
    }
};