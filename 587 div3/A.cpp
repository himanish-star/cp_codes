#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnta=0,cntb=0;
    string dest;
    int changes=0;
    for(int i=0;i<n;i+=2) {
        if(s[i]=='a' && s[i+1]=='a') {
            dest.push_back('a');
            changes++;
            dest.push_back('b');
        } else if(s[i]=='b' && s[i+1]=='b') {
            dest.push_back('a');
            changes++;
            dest.push_back('b');
        } else {
            dest.push_back(s[i]);
            dest.push_back(s[i+1]);
        }
    }


    cout<<changes<<endl;

    if(changes)
        cout<<dest<<endl;
    else
        cout<<s<<endl;
}