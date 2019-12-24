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

        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int lo=0,mid=0,high=n-1;

        while(mid<=high && high>=0 && mid<n && lo<n) {
            if(arr[mid]==1) {
                mid++;
            } else if(arr[mid]==2) {
                int temp=arr[high];
                arr[high]=arr[mid];
                arr[mid]=temp;
                high--;
            } else {
                int temp=arr[lo];
                arr[lo]=arr[mid];
                arr[mid]=temp;
                lo++;
                mid++;
            }
        }

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
	return 0;
}