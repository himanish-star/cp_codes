class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<string> stk;
        
        for(int i=0;i<S.size();i++) {
            if(S[i]=='(') {
                stk.push("(");
            } else {
                int score=0;
                while(stk.size() && stk.top()!="(") {
                    score+=stoi(stk.top());
                    stk.pop();
                }
                stk.pop();
                if(score)
                    stk.push(to_string(2*score));
                else
                    stk.push("1");
            }
        }
        
        int score=0;
        while(stk.size()) {
            score += stoi(stk.top());
            stk.pop();
        }
        return score;
    }
};