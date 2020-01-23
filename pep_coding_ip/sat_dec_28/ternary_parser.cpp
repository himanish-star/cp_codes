class Solution {
public:
    /**
     * @param expression: a string, denote the ternary expression
     * @return: a string
     */
    string parseTernary(string &expression) {
        stack<char> stk;
        
        for(int i=expression.size()-1;i>=0;i--) {
            if(expression[i]=='?') {
                stk.push('?');
            } else if(expression[i]==':') {
                stk.push(':');
            } else {
                if(stk.size() && stk.top()=='?') {
                    stk.pop();
                    char c1;
                    while(stk.size() && stk.top()!=':') {
                        c1=stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    char c2=stk.top();
                    stk.pop();
                    char cnd=expression[i];
                    if(cnd=='T') {
                        stk.push(c1);
                    } else if(cnd=='F') {
                        stk.push(c2);
                    }
                } else {
                    stk.push(expression[i]);
                }
            }
        }
        
        return string(1,stk.top());
    }
};