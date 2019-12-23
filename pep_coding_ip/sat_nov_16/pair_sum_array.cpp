#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
    cin>>t;

    while(t--) {
        int n,tar;
        cin>>n>>tar;

        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        int ib=0,ie=n-1;
        bool found=false;
        while(ib<arr.size() && ie>=0) {
            if(ib!=ie && arr[ib]+arr[ie]==tar) {
                cout<<"Yes"<<endl;
                found=true;
                break;
            } else if(arr[ib]+arr[ie]>tar) {
                ie--;
            } else {
                ib++;
            }
        }

        if(!found)
            cout<<"No"<<endl;
    }
	return 0;
}