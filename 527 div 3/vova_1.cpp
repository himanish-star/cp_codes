#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i] %= 2;
    }

    for(int i=0;i<n-1;i++) {
        if(a[i] && a[i+1]) {
            a[i] = 0;
            a[i+1] = 0;
            i++;
        }
    }


    int count = 0;
    for(int i=0;i<n;i++) {
        if(!a[i])
            count++;
    }

    if(count==n) {
        cout<<"YES";
        return 0;
    } else {
        count = 0;
    }

    for(int i=0;i<n-1;i++) {
        if(!a[i] && !a[i+1]) {
            a[i] = 1;
            a[i+1] = 1;
            i++;
        }
    }

    for(int i=0;i<n;i++) {
        if(a[i])
            count++;
    }
    if(count==n) {
        cout<<"YES";
        return 0;
    } else {
        count = 0;
    }

    for(int i=0;i<n-1;i++) {
        if(a[i] && a[i+1]) {
            a[i] = 0;
            a[i+1] = 0;
            i++;
        }
    }

    for(int i=0;i<n;i++) {
        if(!a[i])
            count++;
    }

    if(count==n) {
        cout<<"YES";
        return 0;
    } else {
        cout<<"NO";
    }

    return 0;
}
