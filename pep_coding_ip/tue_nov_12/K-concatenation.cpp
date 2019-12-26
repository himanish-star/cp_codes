#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;

        ll arr[n],sumref=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sumref+=arr[i];
        }

        ll ms1,ms2;
        ll ls=arr[0],ms=arr[0];
        
        for(int i=1;i<n;i++) {
            ll val;
            if(i>=n) {
                val=arr[i%n];
            } else {
                val=arr[i];
            }
            
            if(val>=0) {
                ls+=val;
                ms=max(ms,ls);
            } else {
                ms=max(val,ms);
                
                ls+=val;
                if(ls<0)
                    ls=0;
            }
        }

        ms1=ms;

        ls=arr[0],ms=arr[0];
        
        if(k==1) {
            cout<<ms1<<endl;
            continue;
        }
        
        for(int i=1;i<n*2;i++) {
            ll val;
            if(i>=n) {
                val=arr[i%n];
            } else {
                val=arr[i];
            }
            
            if(val>=0) {
                ls+=val;
                ms=max(ms,ls);
            } else {
                ms=max(val,ms);
                
                ls+=val;
                if(ls<0)
                    ls=0;
            }
        }

        ms2=ms;

        if(sumref>0) 
            cout<<max(sumref*k,(k-2)*sumref+ms2)<<endl;
        else
            cout<<max(ms1,ms2)<<endl;
    }
    return 0;
}