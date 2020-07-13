#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, tc=1;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++) 
            cin>>arr[i];

        int ans=0;
        int msf=0;

        if(n==1) {
            ans = arr[0]==0 ? 0 : 1;
            printf("Case #%d: %d\n",tc,1);
            tc++;
            continue;
        }
            
        for(int i=0;i<n;i++) {
            if(arr[i]>msf && i+1<n && arr[i]>arr[i+1])
                ans++;

            if(i==n-1 && arr[i]>msf)
                ans++;
            
            msf=max(msf,arr[i]);
        }

        printf("Case #%d: %d\n",tc,ans);
        tc++;
    }
}