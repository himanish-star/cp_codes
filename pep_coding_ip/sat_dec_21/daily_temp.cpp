class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ng(T.size(),-1);
        
        stack<int> s;
        s.push(0);
        for(int i=1;i<T.size();i++) {
            while(s.size() && T[i]>T[s.top()]) {
                ng[s.top()] = i;
                s.pop();
            }
            
            s.push(i);
        }
        
        for(int i=0;i<T.size();i++) {
            ng[i]=max(0,ng[i]-i);
            
        }
        return ng;
    }
};