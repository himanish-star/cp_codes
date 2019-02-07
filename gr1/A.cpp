#include<bits/stdc++.h>

using namespace std;

int main() {
    int b,k;
    cin>>b>>k;

    int oddCount = 0, evenCount = 0;
    for(int i=0;i<k;i++) {
        int a;
        cin>>a;
        if(i!=k-1) {
            if(a%2==0 || b%2==0) {
                evenCount++;
            } else {
                oddCount++;
            }
        } else {
            if(a%2) {
                oddCount++;
            } else {
                evenCount++;
            }
        }
    }
    if(oddCount%2==0) {
        cout<<"even"<<endl;
    } else {
        cout<<"odd"<<endl;
    }
    // cout<<oddCount<<" "<<evenCount<<endl;
    return 0;
}
