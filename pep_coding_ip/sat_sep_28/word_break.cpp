#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string,int> dp;
    map<string,int> dict;
    
    bool dfs(string s,vector<string>& wordDict) {
        if(!s.size()) {
            return false;
        }
        
        if(dp.find(s)!=dp.end()) {
            return dp[s]==1;
        }
        
        if(dict.find(s)!=dict.end()) {
            return true;
        }
        
        string temp="";
        bool possible=false;
        for(int i=0;i<s.size();i++) {
            temp+=s[i];
            
            if(dict.find(temp)!=dict.end())
                possible = possible || dfs(s.substr(i+1,s.size()-i),wordDict);
        }
        
        dp[s] = possible ? 1:0;
        return possible;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        dict.clear();
        for(int i=0;i<wordDict.size();i++) {
            dict.insert(make_pair(wordDict[i],1));
        }
        return dfs(s,wordDict);
    }
};