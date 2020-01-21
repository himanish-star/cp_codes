class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int idx=0;
        for(int i=0;i<pushed.size();i++) {
            s.push(pushed[i]);
            while(s.size() && idx<popped.size() && s.top()==popped[idx]) {
                idx++;
                s.pop();
            }
        }
        
        return s.size()==0;
    }
};