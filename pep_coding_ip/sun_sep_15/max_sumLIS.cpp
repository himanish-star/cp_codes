#include<bits/stdc++.h>

using namespace std;

int maxSumLIS(int arr[], int n) {
    int lis[n][2]={{0,0}};
    
    lis[0][0]=1;
    lis[0][1]=arr[0];

    int ans=arr[0];
    for(int i=1;i<n;i++) {
        lis[i][0]=1;
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j]) {
                lis[i][0]=max(lis[i][0],1+lis[j][0]);
            }
        }

        lis[i][1]=arr[i];
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j] && lis[i][0]-1==lis[j][0]) {
                lis[i][1]=max(lis[i][1],arr[i]+lis[j][1]);
            }
        }
        ans=max(ans,lis[i][1]);
    }

    for(int i=0;i<n;i++)
        cout<<lis[i][1]<<" ";
    
    cout<<endl;

    for(int i=0;i<n;i++)
        cout<<lis[i][0]<<" ";
    
    cout<<endl;

    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        // cout<<endl;
        cout<<maxSumLIS(arr,n)<<endl;
    }
    return 0;
}