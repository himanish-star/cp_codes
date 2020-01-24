#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;
        
        stack<char> stk;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='{') {
                stk.push('{');
            } else {
                if(stk.size() && stk.top()=='{')
                    stk.pop();
                else
                    stk.push('}');
            }
        }
        
        if(stk.size()%2==0) {
            int rc=0,lc=0;
            while(stk.size()) {
                if(stk.top()=='{')
                    lc++;
                else
                    rc++;
                stk.pop();
            }
            int ans=0;
            if(lc%2!=0) {
                ans=(lc-1)/2;
                ans+=(rc-1)/2;
                ans+=2;
            } else {
                ans=lc/2;
                ans+=rc/2;
            }
            cout<<ans<<endl;
        } else if(stk.size()%2!=0) {
            cout<<-1<<endl;  
        } else {
            cout<<0<<endl;
        }
    }
	return 0;
}