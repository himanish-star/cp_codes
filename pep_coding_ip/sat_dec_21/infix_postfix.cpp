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
        pri['^']=3;
        for(int i=0;i<s.size();i++) {
            if((s[i]>='a' && s[i]<='z') || ((s[i]>='A' && s[i]<='Z'))) {
                cout<<s[i];
            } else if(s[i]=='(') {
                stk.push('(');
            } else if(s[i]==')') {
                while(stk.size() && stk.top()!='(') {
                    cout<<stk.top();
                    stk.pop();
                }
                if(stk.size())
                    stk.pop();
            } else {
                while(stk.size() && stk.top()!='(' && pri[s[i]]<=pri[stk.top()]) {
                    cout<<stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        
        while(stk.size()) {
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    }
	return 0;
}