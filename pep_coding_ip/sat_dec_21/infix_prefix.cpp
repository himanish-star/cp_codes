#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;
        
        stack<char> stk;
        unordered_map<char,int> pri;
        pri['+']=1;
        pri['-']=1;
        pri['*']=2;
        pri['/']=2;
        string res;
        for(int i=s.size()-1;i>=0;i--) {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
                res.push_back(s[i]);
            } else if(s[i]==')') { 
                stk.push(')');
            } else if(s[i]=='(') {
                while(stk.size() && stk.top()!=')') {
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            } else {
                while(stk.size() && stk.top()!=')' && pri[s[i]]<=pri[stk.top()]) {
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        
        while(stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
    return 0;
}