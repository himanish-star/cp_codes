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
    int moves[4][2]={
        {+1,0},  
        {-1,0},  
        {0,+1},  
        {0,-1},  
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        if(!grid.size())
            return 0;
        
        int N=grid.size();
        Subset subsets[4*N*N];
        for(int i=0;i<4*N*N;i++)
            subsets[i]=Subset{i,0};
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                int root=4*(N*i+j);
                
                if(grid[i][j]!='/') {
                    unite(subsets,root+0,root+2);
                    unite(subsets,root+1,root+3);
                }
                
                if(grid[i][j]!='\\') {
                    unite(subsets,root+0,root+1);
                    unite(subsets,root+2,root+3);
                }
                
                if(i+1<N) {
                    unite(subsets,root+3,4*(N*(i+1)+j)+0);
                }
                
                if(j+1<N) {
                    unite(subsets,root+2,4*(N*(i)+j+1)+1);
                }
                
                if(i-1>=0) {
                    unite(subsets,root+0,4*(N*(i-1)+j)+3);
                }
                
                if(j-1>=0) {
                    unite(subsets,root+1,4*(N*(i)+j-1)+2);
                }
            }
        }
        
        set<int> ugps;
        for(int i=0;i<4*N*N;i++)
            ugps.insert(fp(subsets,i));
        return ugps.size();
    }
};