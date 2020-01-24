#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;
        
        stack<char> stk;
        bool duplicate=false;
        for(int i=0;i<s.size();i++) {
            if(s[i]==')') {
                int er=0;
                while(stk.size() && stk.top()!='(') {
                    stk.pop();
                    er++;
                }
                stk.pop();
                if(er==0) {
                    duplicate=true;
                    break;
                }
            } else {
                stk.push(s[i]);
            }
        }
        
        if(duplicate) {
            cout<<"duplicate"<<endl;
        } else {
            cout<<"no duplicate"<<endl;
        }
    }
    return 0;
}