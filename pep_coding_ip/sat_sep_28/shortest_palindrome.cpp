class Solution {
    struct Coord {
        int s;
        int e;
    };
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        if(!n)
            return s;
        
        string res=s;
        reverse(res.begin(),res.end());
        
        if(res==s)
            return s;
        
        vector<vector<pair<int,Coord>>> dp(n,vector<pair<int,Coord>> (n,make_pair(0,Coord{0,0})));
        
        for(int l=1;l<=n;l++) {
            for(int i=0;i+l-1<n;i++) {
                int j=i+l-1;
                if(l==1) {
                    dp[i][j].first=1;
                    dp[i][j].second=Coord{i,j};
                } else if(l==2) {
                    if(s[i]==s[j]) {
                        dp[i][j].first=2;
                        dp[i][j].second=Coord{i,j};
                    } else {
                        dp[i][j].first=1;
                        dp[i][j].second=Coord{i,i};
                    }
                } else {
                    if(s[i]==s[j] && dp[i+1][j-1].first==j-i-1) {
                        dp[i][j].first = 2 + dp[i+1][j-1].first;
                        dp[i][j].second=Coord{i,j};
                    } else {
                        dp[i][j].first = dp[i+1][j-1].first;
                        dp[i][j].second = dp[i+1][j-1].second;
                        
                        if(dp[i][j-1].first > dp[i][j].first) {
                            dp[i][j].first = dp[i][j-1].first;
                            dp[i][j].second = dp[i][j-1].second;
                        }
                        
                        if(dp[i+1][j].first > dp[i][j].first) {
                            dp[i][j].first = dp[i+1][j].first;
                            dp[i][j].second = dp[i+1][j].second;
                        }
                    }
                }
            }
        }
        
        // find longest palindrome from starting
        int idx=0;
        for(int i=1;i<s.size();i++) {
            if(dp[0][i].first==i+1) {
                idx=i;
            }
        }
        
        for(int i=idx+1;i<s.size();i++)
            res.push_back(s[i]);
        
        return res;
    }
};