class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int mid=-1;
        int n=A.size();
        
        if(n==0) {
            return A;
        }
    
        if(n==1) {
            A[0]*=A[0];
            return A;
        }
        
        for(int i=0;i<n;i++) {
            if(A[i]>=0) {
                mid=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++)
            A[i]=pow(A[i],2);
        
        if(mid==0) {
            return A;
        }
        
        vector<int> ans;
        
        int i=mid-1;
        while(i>=0 && mid<n) {
            if(A[i]<A[mid]) {
                ans.push_back(A[i--]);
            } else {
                ans.push_back(A[mid++]);
            }
        }
        
        while(i>=0) {
            ans.push_back(A[i--]);
        }
        
        while(mid<n) {
            ans.push_back(A[mid++]);
        }
        
        return ans;
    }
};