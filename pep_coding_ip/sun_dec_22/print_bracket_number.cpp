#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    
    stack<int> stk;
    int sc=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') {
            sc++;
            stk.push(sc);
            cout<<sc<<" ";
        } else if(s[i]==')') {
            cout<<stk.top()<<" ";
            stk.pop();
        }
    }
    return 0;
}