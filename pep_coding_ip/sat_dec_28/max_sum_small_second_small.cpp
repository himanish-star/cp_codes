#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        ll arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        ll ans=0;
        for(int i=0;i<n-1;i++) {
            ans=max(ans,arr[i]+arr[i+1]);
        }
        cout<<ans<<endl;
    }
	return 0;
}