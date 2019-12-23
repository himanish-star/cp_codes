class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int ib=0,ie=n-1;
        
        if(n==1)
            return A;
        
        while(ib<n && ie>=0 && ie>ib) {
            if(A[ie]%2==0) {
                while(ib<n && A[ib]%2==0) {
                    ib++;
                }
                if(ib<n && ie>ib) {
                    int temp=A[ib];
                    A[ib]=A[ie];
                    A[ie]=temp;
                }
                ie--;
            } else {
                ie--;
            }
        }
        
        // reverse(A.begin(),A.end());
        return A;
    }
};