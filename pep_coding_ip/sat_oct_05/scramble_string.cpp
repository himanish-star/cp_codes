#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int dp[100][100][100];
    
    bool isScrambleUtilP(string& str1,string& str2,int s1,int e1,int s2,int e2) {
        if(str1==str2)
            return true;
        
        if(e1-s1!=e2-s2)
            return false;

        if(e1==s1 && e2==s2) {
            return str1[e1]==str2[e2];
        }
        
        int len=e1-s1+1;
        if(dp[s1][s2][len]!=-1) {
            return dp[s1][s2][len]==1;
        }
        
        // printf("str1[%d-%d] && str2[%d-%d]\n",s1,e1,s2,e2);
        bool ans=false;
        for(int l=1;l<len;l++) {
            string s1l=str1.substr(s1,l);
            string s1r=str1.substr(s1+l,len-l);
            
            string s2l=str2.substr(s2,l);
            string s2r=str2.substr(s2+l,len-l);
            
            string s3l=str2.substr(s2,len-l);
            string s3r=str2.substr(s2+len-l,l);
            
            sort(s1l.begin(),s1l.end());
            sort(s1r.begin(),s1r.end());
            sort(s2l.begin(),s2l.end());
            sort(s2r.begin(),s2r.end());
            sort(s3l.begin(),s3l.end());
            sort(s3r.begin(),s3r.end());

            // cout<<s1l<<" "<<s1r<<endl;
            // cout<<s2l<<" "<<s2r<<endl;
            // cout<<s3l<<" "<<s3r<<endl;
            // cout<<endl;
            if(s1l==s2l && s1r==s2r) {
                ans|=(isScrambleUtilP(str1,str2,s1,s1+l-1,s2,s2+l-1) && isScrambleUtilP(str1,str2,s1+l,e1,s2+l,e2));
            } else if(s1l==s3r && s1r==s3l) {
                ans|=(isScrambleUtilP(str1,str2,s1,s1+l-1,s2+len-l,e2) && isScrambleUtilP(str1,str2,s1+l,e1,s2,s2+len-l-1));
            }
        }
        
        dp[s1][s2][len]=ans==true?1:0;
        return ans;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1==s2) {
            return true;
        }
        
        if(s1.size()!=s2.size()) {
            return false;
        }
        
        int n=s1.size();
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                for(int k=0;k<=n;k++) {
                    dp[i][j][k]=-1;
                }
            }
        }
        
        return isScrambleUtilP(s1,s2,0,s1.size()-1,0,s2.size()-1);
    }
};
