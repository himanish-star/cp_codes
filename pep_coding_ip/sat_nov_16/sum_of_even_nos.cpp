class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result(queries.size());
        
        int sum=0;
        for(int i=0;i<A.size();i++) {
            if(A[i]%2==0)
                sum+=A[i];
        }
        
        for(int i=0;i<queries.size();i++) {
            int uval=queries[i][0];
            int uidx=queries[i][1];
            
            if(A[uidx]%2==0) {
                sum-=A[uidx];
            }
            
            A[uidx]+=uval;
            
            if(A[uidx]%2==0) {
                sum+=A[uidx];
            }
            result[i]=sum;
        }
        return result;
    }
};