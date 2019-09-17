#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        
        int lps[len][len];
        
        for(int l=1;l<=len;l++) {
            for(int i=0;i+l-1<len;i++) {
                int j=i+l-1;
                if(l==1) {
                    lps[i][j]=1;
                    continue;
                }
                if(l==2) {
                    if(s[i]==s[j]) {
                        lps[i][j]=2;
                    } else {
                        lps[i][j]=1;
                    }
                    continue;
                }
                
                if(s[i]==s[j]) {
                    lps[i][j]=2+lps[i+1][j-1];
                } else {
                    lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
                }
            }
        }
        
        return lps[0][len-1];
    }
};