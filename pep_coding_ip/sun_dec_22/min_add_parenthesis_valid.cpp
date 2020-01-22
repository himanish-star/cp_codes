class Solution {
public:
    int minAddToMakeValid(string S) {
        if(!S.size())
            return 0;
        
        stack<char> s;
        s.push(S[0]);
        
        for(int i=1;i<S.size();i++) {
            if(S[i]=='(')
                s.push('(');
            else {
                if(s.size() && s.top()=='(' && S[i]==')') {
                    s.pop();
                } else {
                    s.push(S[i]);
                }
                
            }
        }
        
        return s.size();
    }
};