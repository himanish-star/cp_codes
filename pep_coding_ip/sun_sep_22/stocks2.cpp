#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1 || prices.size()==0) {
            return 0;
        }
        
        int profit=0;
        int cash=-prices[0];
        
        for(int i=1;i<prices.size();i++) {
            if(prices[i]+cash>0) {
                //make a profit
                profit+=prices[i]+cash;
                cash=-prices[i];
            } else {
                cash=-prices[i];
            }
        }
        
        return profit;
    }
};

