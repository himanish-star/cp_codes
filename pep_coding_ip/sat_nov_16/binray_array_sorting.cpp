#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int i0=0;
        for(int i=1;i<n;i++) {
            if(arr[i]==0) {
              while(i0<n && arr[i0]==0) {
                    i0++;
                }
                if(i0<n && i>i0) {
                    int temp=arr[i];
                    arr[i]=arr[i0];
                    arr[i0]=temp;
                    i0++;
                }  
            }
        }

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
	return 0;
}