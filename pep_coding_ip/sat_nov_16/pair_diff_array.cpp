#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;

    while(t--) {
        int n,diff;
        cin>>n>>diff;

        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        int ib=0,ie=1;
        bool found=false;
        while(ie<n && ib<n) {
            if(ie!=ib && arr[ie]-arr[ib]==diff) {
                found=true;
                cout<<1<<endl;
                break;
            } else if(arr[ie]-arr[ib]<diff) {
                ie++;
            } else {
                ib++;
            }
        }
        
        if(!found)
            cout<<-1<<endl;
    }
	return 0;
}