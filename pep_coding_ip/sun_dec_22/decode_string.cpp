class Solution {
public:
    string decodeString(string s) {
        if(!s.size())
            return s;
        
        stack<string> stk;
        
        for(int i=0;i<s.size();) {
            if(s[i]=='[') {
                stk.push(string(1,s[i]));
                i++;
            } else if(s[i]==']') {
                string ptrn="";
                while(stk.size() && stk.top()!="[") {
                    reverse(stk.top().begin(),stk.top().end());
                    ptrn+=stk.top();
                    stk.pop();
                }
                stk.pop();
                int cnt=stoi(stk.top());
                stk.pop();
                string temp="";
                reverse(ptrn.begin(),ptrn.end());
                while(cnt--) {
                    temp+=ptrn;
                }
                stk.push(temp);
                i++;
            } else if(s[i]>='0' && s[i]<='9') {
                string num="";
                while(s[i]>='0' && s[i]<='9') {
                    num.push_back(s[i]);
                    i++;
                }
                stk.push(num);
            } else {
                stk.push(string(1,s[i]));
                i++;
            }
        }
        
        string res="";
        while(stk.size()) {
            reverse(stk.top().begin(),stk.top().end());
            res+=stk.top();
            stk.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};