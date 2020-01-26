#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t;
	cin>>t;
	
	while(t--) {
	    ll n;
	    cin>>n;
	    
	    ll arr[n];
	    vector<ll> ng(n,-1);
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	       
	    stack<ll> stk;
	    for(ll i=0;i<n;i++) {
	        while(stk.size() && arr[stk.top()]<arr[i]) {
	            ng[stk.top()]=i;
	            stk.pop();
	        }
	        stk.push(i);
	    }
	    for(ll i=0;i<n;i++) {
	        if(ng[i]!=-1) cout<<arr[ng[i]]<<" ";
	        else cout<<"-1 ";
	    }
	    cout<<endl;
	}
	return 0;
}