class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk;
        for(int i=0;i<S.size();i++) {
            if(S[i]=='#') {
                if(stk.size())
                    stk.pop();
            } else {
                stk.push(S[i]);
            }
        }
        
        string res1;
        while(stk.size()) {
            res1.push_back(stk.top());
            stk.pop();
        }
        
        for(int i=0;i<T.size();i++) {
            if(T[i]=='#') {
                if(stk.size())
                    stk.pop();
            } else {
                stk.push(T[i]);
            }
        }
        
        string res2;
        while(stk.size()) {
            res2.push_back(stk.top());
            stk.pop();
        }
        
        return res1==res2;
    }
};