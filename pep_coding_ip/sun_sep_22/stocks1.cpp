#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        
        int bigr[prices.size()];
        
        int n=prices.size();
        int cbr=prices[n-1];
        for(int i=n-2;i>=0;i--) {
            bigr[i]=cbr;
            cbr=max(cbr,prices[i]);
        }
        
        int profit=0;
        for(int i=0;i<n-1;i++) {
            profit=max(profit,bigr[i]-prices[i]);
        }
        
        return profit;
    }
    
};