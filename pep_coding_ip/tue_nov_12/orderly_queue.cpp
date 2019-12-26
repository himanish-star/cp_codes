class Solution {
public:
    string orderlyQueue(string s, int K) {
        if(K==1) {
            string res=s;
            for(int i=0;i<s.size();i++) {
                string t = s.substr(i) + s.substr(0,i);
                if(t<res)
                    res=t;
            }
            return res;
        } else {
            sort(s.begin(),s.end());
            return s;
        }
    }
};