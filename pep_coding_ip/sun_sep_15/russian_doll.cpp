#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(!envelopes.size()) {
            return 0;
        }
        
        sort(envelopes.begin(),envelopes.end());
        
//         for(int i=0;i<envelopes.size();i++) {
//             cout<<envelopes[i][0]<<" ";
//         }
//         cout<<endl;
        
        int n=envelopes.size();
        int lis[n];
        
        lis[0]=1;
        int ans=1;
        for(int i=1;i<n;i++) {
            lis[i]=1;
            for(int j=0;j<i;j++) {
                if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0]) {
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
            ans=max(ans,lis[i]);
        }
        
        return ans;
    }
};