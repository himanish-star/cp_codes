#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;

    int cmparray[s.size()] = {0};

    char minSoFar = s[0];
    for(int i=1;i<s.size();i++) {
        if(minSoFar<s[i]) {
            cmparray[i]=1;
        }
        minSoFar=min(minSoFar,s[i]);
    }

    for(int i=0;i<s.size();i++) {
        if(cmparray[i]) {
            cout<<"Ann"<<endl;
        } else {
            cout<<"Mike"<<endl;
        }
    }
}