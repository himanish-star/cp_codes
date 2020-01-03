#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int s;
        cin>>s;

        int arr[3];
        for(int i=0;i<3;i++) {
            cin>>arr[i];
        }

        int hits=0,cum=0;
        for(int i=0;i<3;i++) {
            cum+=arr[i];
            if(cum>s) {
                cum=arr[i];
                hits++;
            }
        }
        cout<<hits+1<<endl;
    }
}