class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<num.size();i++) {
            while(s.size() && k && num[s.top()]>num[i]) {
                k--;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(k && s.size()) {
            k--;
            s.pop();
        }
        
        string res;
        while(s.size()) {
            res.push_back(num[s.top()]);
            s.pop();
        }
                
        int idx=res.size()-1;
        while(idx>=0 && res[idx]=='0') {
            res.pop_back();
            idx--;
        }
        
        reverse(res.begin(),res.end());
        
        if(res.size()==0)
            res="0";
        
        return res;
    }
};