class Solution {
public:
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
        
        if(subsets[xset].rank>subsets[yset].rank) {
            subsets[yset].parent=xset;
        } else if(subsets[xset].rank<subsets[yset].rank) {
            subsets[xset].parent=yset;
        } else {
            subsets[xset].rank++;
            subsets[yset].parent=xset;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if(!M.size())
            return 0;
        
        Subset subsets[M.size()];
        for(int i=0;i<M.size();i++) {
            subsets[i]=Subset{i,0};
        }
        
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[i].size();j++) {
                if(M[i][j]==1 && fp(subsets,i)!=fp(subsets,j))
                    unite(subsets,i,j);
            }
        }
        
        set<int> ugps;
        for(int i=0;i<M.size();i++)
            ugps.insert(fp(subsets,i));
        return ugps.size();
    }
};