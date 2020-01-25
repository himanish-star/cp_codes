#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;
        
        stack<string> stk;
        for(int i=s.size()-1;i>=0;i--) {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
                stk.push(string(1,s[i]));
            } else {
                string e1=stk.top();stk.pop();
                string e2=stk.top();stk.pop();
                stk.push("("+e1+string(1,s[i])+e2+")");
            }
        }
        cout<<stk.top()<<endl;
    }
    return 0;
}