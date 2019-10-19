#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    
	    int he[n],le[n];
	    for(int i=0;i<n;i++)
	        cin>>he[i];
	       
	    for(int i=0;i<n;i++)
	        cin>>le[i];
	        
	    int dp[n+1];
	    
	    dp[0]=0;
	    dp[1]=max(he[0],le[0]);
	    for(int i=2;i<=n;i++) {
	        dp[i]=max(he[i-1]+dp[i-2],le[i-1]+dp[i-1]);
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}