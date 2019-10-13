#include<bits/stdc++.h>
using namespace std;

map<string,int> dp;

int min_flips(string s) {
    

    int len=s.size(),c=0,ans=0,ans2=0,c2=1;
    for(int i=0;i<len;i++) {
        if(s[i]!='0'+c)
            ans++;
        
        if(s[i]!='0'+c2)
            ans2++;
        
        c2=(c2+1)%2;
        c=(c+1)%2;
    }

    // cout<<ans<<ans2<<endl;
    return min(ans,ans2);
    
}

int main()
 {
	int t;
	cin>>t;
	
	while(t--) {
	    string s;
	    cin>>s;
	    
	    cout<<min_flips(s)<<endl;
	}
	return 0;
}