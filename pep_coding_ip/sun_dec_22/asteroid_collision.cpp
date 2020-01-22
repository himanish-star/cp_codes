class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        
        for(int i=1;i<asteroids.size();i++) {
            int curr=asteroids[i];
            if(curr<0) {
                bool noPush = false;
                while(s.size() && s.top()>0 && curr<0) {
                    int top=s.top();
                    s.pop();
                    if(abs(top)>abs(curr))
                        curr=top;
                    else if(abs(top)==abs(curr)) {
                        noPush = true;
                        break;
                    }
                }
                if(!noPush)
                    s.push(curr);
            } else {
                s.push(curr);
            }
        }
        
        vector<int> res;
        while(s.size()) {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};