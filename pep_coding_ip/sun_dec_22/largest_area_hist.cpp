#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	
	while(t--) {
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    vector<int> nsr(n,-1), nsl(n,-1);
	    
	    //compute next smaller right
	    stack<int> st; st.push(0);
	    
	    for(int i=1;i<n;i++) {
	       while(st.size() && arr[i]<arr[st.top()]) {
	           nsr[st.top()]=i; st.pop();
	       } 
	       st.push(i);
	    }
	    
	    stack<int> st2; st2.push(n-1);
	    for(int i=n-2;i>=0;i--) {
	        while(st2.size() && arr[i]<arr[st2.top()]) {
	           nsl[st2.top()]=i; st2.pop();
	       } 
	       st2.push(i);
	    }
	    
	    long long max_area=0;
	    for(int i=0;i<n;i++) {
	        long long area;
	        long long base=0;
	        base+=nsr[i]!=-1?nsr[i]-i:n-i;
	        base+=nsl[i]!=-1?-nsl[i]+i:i+1;
	        base--;
	        area=base*arr[i];
	        // cout<<nsl[i]<<" "<<nsr[i]<<" , h = "<<arr[i]<<" b = "<<base<<endl;
	        max_area=max(area,max_area);
	    }
	    cout<<max_area<<endl;
	}
	return 0;
}