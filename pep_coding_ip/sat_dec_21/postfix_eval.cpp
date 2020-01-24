#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	
	while(t--) {
	    string s;
	    cin>>s;
	    
	    stack<int> stk;
	    for(int i=0;i<s.size();i++) {
	        if(s[i]>='0' && s[i]<='9') {
	            stk.push(s[i]-'0');
	        } else {
	            int e2=stk.top();stk.pop();
	            int e1=stk.top();stk.pop();
	            if(s[i]=='*') {
	                e1*=e2;
	            } else if(s[i]=='/') {
	                e1/=e2;
	            } else if(s[i]=='+') {
	                e1+=e2;
	            } else {
	                e1-=e2;
	            }
	            stk.push(e1);
	        }
	    }
	    cout<<stk.top()<<endl;
	}
	return 0;
}