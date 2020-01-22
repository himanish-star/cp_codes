#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    int max1=INT_MIN,max2=INT_MIN;
    
    for(int i=0;i<n;i++) {
        int ele;
        cin>>ele;
        
        if(ele>=max1) {
            max2=max1;
            max1=ele;
        } else if(ele>max2) {
            max2=ele;
        }
    }
    
    cout<<max1+max2<<endl;
    return 0;
}