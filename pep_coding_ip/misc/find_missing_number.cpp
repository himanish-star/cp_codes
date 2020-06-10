#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int s=0, e=n-1, mid;
        bool found=false;
        while(!found && s+1<e) {
            mid=(s+e)/2;
            // cout<<s<<" "<<e<<endl;
            float rd=(arr[e]-arr[mid])/(float)(e-mid);
            float ld=(arr[mid]-arr[s])/(float)(mid-s);

            if(rd>ld) {
                s=mid;
            } else if(rd<ld) {
                e=mid;
            }
        }

        int d=(arr[n-1]-arr[0])/n;
        cout<<arr[s]+d<<endl;
    }
	return 0;
}