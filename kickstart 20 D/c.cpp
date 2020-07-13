#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, tc=1;
    cin>>t;
    
    while(t--) {
        int n,ans=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
        }
        int note1=0,note2=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                note1++;
                note2=0;
                if(note1==4){
                    note1=0;
                    ans++;
                }
            }
            else if(arr[i]<arr[i-1]){
                note2++;
                note1=0;
                if(note2==4){
                    note2=0;ans++;
                    
                }
            }
        }
        printf("Case #%d: %d\n",tc,ans); tc++;
    }

    return 0;
}