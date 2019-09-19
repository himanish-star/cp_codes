#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int n_cnt=0,z_cnt=0;

    for(int i=0;i<n;i++) {
        char c;
        cin>>c;

        if(c=='n')
            n_cnt++;
        else if(c=='z')
            z_cnt++;
    }

    while(n_cnt--) {
        cout<<1<<" ";
    }
    while(z_cnt--) {
        cout<<0<<" ";
    }
}