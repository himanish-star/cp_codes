#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1) {
            cout<<"NO"<<endl;
            continue;
        }
        if(n==2) {
            if(s[0]<s[1]) {
                cout<<"YES"<<endl;
                cout<<2<<endl;
                cout<<s[0]<<" "<<s[1]<<endl;
            } else {
                cout<<"NO"<<endl;
            }
            continue;
        }

        string temp="";
        for(int i=1;i<n;i++)
            temp+=s[i];

        cout<<"YES"<<endl;
        cout<<2<<endl;
        cout<<s[0]<<" "<<temp<<endl;
    }
    return 0;
}
