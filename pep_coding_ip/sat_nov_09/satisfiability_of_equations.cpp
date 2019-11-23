class Solution {
    struct Subset {
        int parent;
        int rank;
    };
    
    int fp(Subset subsets[],int i) {
        if(i!=subsets[i].parent)
            subsets[i].parent=fp(subsets,subsets[i].parent);
        return subsets[i].parent;
    }
    
    void unite(Subset subsets[],int x,int y) {
        int xset=fp(subsets,x);
        int yset=fp(subsets,y);
        
        if(xset==yset)
            return;
        
        if(subsets[xset].rank>subsets[yset].rank) {
            subsets[yset].parent=xset;
        } else if(subsets[xset].rank<subsets[yset].rank) {
            subsets[xset].parent=yset;
        } else {
            subsets[xset].rank++;
            subsets[yset].parent=xset;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
       if(!equations.size())
           return true;
        Subset subsets[26];
        for(int i=0;i<26;i++)
            subsets[i]=Subset{i,0};
        
        for(int i=0;i<equations.size();i++) {
            int x=equations[i][0]-'a';
            int y=equations[i][3]-'a';
            string condition=equations[i].substr(1,2);
            if(condition=="==")
                unite(subsets,x,y);
        }
        
        for(int i=0;i<equations.size();i++) {
            int x=equations[i][0]-'a';
            int y=equations[i][3]-'a';
            string condition=equations[i].substr(1,2);
            if(condition=="!=") {
                int xset=fp(subsets,x);
                int yset=fp(subsets,y);
                
                if(xset==yset)
                    return false;
            }
        }
        
        return true;
    }
};