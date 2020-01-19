class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ng(2*nums.size(),-1);
        
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<2*nums.size();i++) {
            int idx=i;
            if(i>=nums.size())
                idx=i-nums.size();
            
            while(s.size() && nums[idx]>nums[s.top()]) {
                ng[s.top()]=idx;
                s.pop();
            }
            s.push(idx);
        }
        
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            if(ng[i]!=-1)
                res.push_back(nums[ng[i]]);
            else
                res.push_back(ng[i]);
        }
        
        return res;
    }
};