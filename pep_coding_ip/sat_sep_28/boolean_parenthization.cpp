#include<bits/stdc++.h>

using namespace std;

int mod=1003;

char evaluate(bool l,bool r,char ops) {
    switch(ops) {
        case '|':
            return (l|r) ? 'T':'F';
        case '^':
            return (l^r) ? 'T':'F';
        case '&':
            return (l&r) ? 'T':'F';
    }
}

int solve(string s,int n) {
    int dp[n][n]={0};
    int dpf[n][n]={0};

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dp[i][j]=0;
            dpf[i][j]=0;
        }
    }

    for(int l=1;l<=n;l++) {
        for(int i=0;i+l-1<n;i+=2) {
            int j=i+l-1;
            if(l==1) {
                if(s[i]=='T')
                    dp[i][j]=1;
                else
                    dpf[i][j]=1;
            } else if(l%2!=0) {
                for(int k=i+1;k<j;k++) {
                    // operator at k position
                    char ops=s[k];

                    if(evaluate(true,true,s[k])=='T') {
                        dp[i][j]+=dp[i][k-1]*dp[k+1][j];
                    } else {
                        dpf[i][j]+=dp[i][k-1]*dp[k+1][j];
                    }
                    
                    dp[i][j]%=mod;
                    dpf[i][j]%=mod;
                    
                    if(evaluate(true,false,s[k])=='T') {
                        dp[i][j]+=dp[i][k-1]*dpf[k+1][j];
                    } else {
                        dpf[i][j]+=dp[i][k-1]*dpf[k+1][j];
                    }

                    dp[i][j]%=mod;
                    dpf[i][j]%=mod;

                    if(evaluate(false,true,s[k])=='T') {
                        dp[i][j]+=dpf[i][k-1]*dp[k+1][j];
                    } else {
                        dpf[i][j]+=dpf[i][k-1]*dp[k+1][j];
                    }
                    
                    dp[i][j]%=mod;
                    dpf[i][j]%=mod;

                    if(evaluate(false,false,s[k])=='T') {
                        dp[i][j]+=dpf[i][k-1]*dpf[k+1][j];
                    } else {
                        dpf[i][j]+=dpf[i][k-1]*dpf[k+1][j];
                    }
                    
                    dp[i][j]%=mod;
                    dpf[i][j]%=mod;
                }
            }
        }
    }

    // cout<<endl;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[0][n-1];
}

int main()
 {
	int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        cout<<solve(s,n)<<endl;
    }
	return 0;
}