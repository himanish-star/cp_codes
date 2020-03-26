#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i];
	       
	    int k;
	    cin>>k;
	    
	    queue<int> qu;
	    for(int i=0;i<k-1;i++) {
	        qu.push(v[i]);
	    }
	 
	    for(int i=k-1;i<n;i++) {
	        qu.push(v[i]);
            int pc=0;
	        while(qu.size() && qu.front()>=0) {
	            qu.pop();
                pc++;
	        }
	        if(!qu.size())
	            cout<<0<<" ";
	        else {
	            cout<<qu.front()<<" ";
                if(qu.size()==k) qu.pop();
            }
	    }
	    cout<<endl;
	}
	return 0;
}