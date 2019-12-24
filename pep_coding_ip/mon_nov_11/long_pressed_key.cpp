class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int idx=0;
        
        if(typed[0]!=name[idx])
            return false;
        
        char lc=typed[0];
        int cc=1;
        for(int i=1;i<typed.size();i++) {
            if(typed[i]!=lc) {
                int lcc=0;
                while(idx<name.size() && lc==name[idx]) {
                    idx++;
                    lcc++;
                }
                lc=typed[i];
                if(lcc>cc || lc!=name[idx]) {
                    return false;
                }
                cc=1;
            } else {
                cc++;
            }
        }
        
        if(cc>=1) {
            while(idx<name.size()) {
                if(lc!=name[idx])
                    return false;
                idx++;
            }
        }
        
        if(idx<name.size())
            return false;
        return true;
    }
};