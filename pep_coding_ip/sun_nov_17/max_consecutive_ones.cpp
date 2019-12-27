class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n=nums.size();
        
        vector<int> l(n),r(n);
        
        //create left
        bool onlyOne=true;
        l[0]=nums[0]==0 ? 0:1;
        for(int i=1;i<n;i++) {
            if(nums[i]==1) {
                l[i]=1+l[i-1];
            } else {
                onlyOne=false;
                l[i]=0;
            }
        }
        
        if(onlyOne)
            return n;
        
        r[n-1]=nums[n-1]==0 ? 0:1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i]==1) {
                r[i]=1+r[i+1];
            } else {
                r[i]=0;
            }
        }
        
        for(int i=0;i<n;i++) {
            cout<<r[i]<<" ";
        }
        cout<<endl;
        
        int mv=0;
       
        if(nums[0]==0)
            mv=max(mv,r[1]);
       
        if(nums[n-1]==0) {
            mv=max(mv,l[n-2]);
        }
       
        for(int i=1;i<n-1;i++) {
            if(nums[i]==0)
                mv=max(mv,l[i-1]+r[i+1]);
        }
        
        return mv+1;
    }
};