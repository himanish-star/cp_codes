class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        
        int mv=arr[n-1],ans=1;
        
        vector<int> mr(n);
        mr[0]=arr[0];
        
        for(int i=1;i<n;i++) {
            mr[i]=max(arr[i],mr[i-1]);
        }
        
        for(int i=n-2;i>=0;i--) {
            if(arr[i]<=mv && mr[i]<=mv) {
                ans++;
                mv=arr[i];
            }
            mv=min(mv,arr[i]);
        }
        
        return ans;
    }
};