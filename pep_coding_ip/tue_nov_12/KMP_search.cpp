class Solution {
public:
    
    vector<int> createTable(string s) {
        vector<int> dp(s.size(),0);
        dp[0]=0;
        
        for(int i=1;i<s.size();i++) {
            int t = dp[i-1];
            
            while(t>0 && s[i]!=s[t]) {
                t = dp[t-1];
            }
            
            if(s[t]==s[i])
                t++;
            
            dp[i]=t;
        }
        
        return dp;
    }
    
    int strStr(string haystack, string needle) {
        
        if(!needle.size())
            return 0;
        
        if(!haystack.size())
            return -1;
        
        vector<int> lps = createTable(needle);
        
        int i=0;
        int j=0;
        
        while(i<haystack.size()) {
            if(haystack[i]==needle[j]) {
                i++;
                j++;
            }
            
            if(j==needle.size()) {
                return i-j;
            }
            
            while(i<haystack.size() && needle[j]!=haystack[i]) {
                if(j)
                    j=lps[j-1];
                else
                    i++;
                
            }
            
        }
        
        return -1;
    }
};