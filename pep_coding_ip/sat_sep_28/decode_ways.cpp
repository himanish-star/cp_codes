#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    map<string,int> dp;
    
    int dfs(string s) {
        if(!s.size()) {
            return 0;
        }
        
        if(s=="0") {
            return 0;
        }
        
        if(dp.find(s)!=dp.end())
            return dp[s];
        
        int ans=0;
        string temp="";
        for(int i=0;i<s.size();i++) {
            temp+=s[i];
            int num=-1;
            if(temp.size()<=2)
                num=stoi(temp);
            if(num>=1 && num<=26 && dp.find(temp)!=dp.end()) {
                int tt=dfs(s.substr(i+1,s.size()-i));
                if(tt!=0) {
                    ans+=tt;
                }
            }
        }
        dp[s]=ans;
        return ans;
    }
    
    int numDecodings(string s) {
        dp.clear();
        
        for(int i=1;i<=26;i++) {
            if(i<=9 || i%10==0) {
                dp.insert(make_pair(to_string(i),1));
            } else {
                dp.insert(make_pair(to_string(i),2));
            }
        }
        
        return dfs(s);
    }
};