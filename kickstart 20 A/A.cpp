#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    int id=1;
    while(t--) {
        int n,b;
        cin>>n>>b;

        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++) {
            if(b>=arr[i]) {
                ans++;
                b-=arr[i];
            }
        }

        printf("Case #%d: %d\n",id,ans);
        id++;
    }
}