#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n,temp;
	    cin>>n;
	    temp=n-1;
	    
	    queue<string> qu;
	    qu.push("1");
	    cout<<1<<" ";
	    while(qu.size() && temp) {
	        int cnt=qu.size();
	        while(cnt-- && temp) {
	            string e=qu.front();
	            qu.pop();
	            
	            if(temp) {
	                cout<<e+"0"<<" ";
	                qu.push(e+"0");
	                temp--;
	            }
	            
	            if(temp) {
	                cout<<e+"1"<<" ";
	                qu.push(e+"1");
	                temp--;
	            }
	        }
	    }
	    cout<<endl;
	}
	return 0;
}