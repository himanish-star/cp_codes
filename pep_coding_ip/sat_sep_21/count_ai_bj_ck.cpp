#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int len=s.size();
        int ac=0,bc=0,cc=0;

        for(int i=0;i<len;i++) {
            if(s[i]=='a') {
                ac=1+2*ac;
            } else if(s[i]=='b') {
                bc=ac+2*bc;
            } else {
                cc=bc+2*cc;
            }   
        }
        cout<<cc<<endl;
    }
    return 0;
}