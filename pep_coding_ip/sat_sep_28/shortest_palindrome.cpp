class Solution {
public:
    string shortestPalindrome(string s) {
        vector<int> dp(2*s.size()+2);
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        string ns=s+"#"+rev;
        dp[0]=0;
        
        for(int i=1;i<ns.size();i++) {
            int t=dp[i-1];
            
            while(t>0 && ns[i]!=ns[t])
                t=dp[t-1];
            
            if(ns[t]==ns[i])
                t++;
            
            dp[i]=t;
        }
        
        return  rev.substr(0,rev.size()-dp[ns.size()-1]) + s;
    }
};