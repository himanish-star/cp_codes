class Solution {
    struct Subset {
        int parent;
        int rank;
        int size;
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
            subsets[xset].size=subsets[xset].size+subsets[yset].size;
        } else if(subsets[xset].rank<subsets[yset].rank) {
            subsets[xset].parent=yset;
            subsets[yset].size=subsets[xset].size+subsets[yset].size;
        } else {
            subsets[xset].rank++;
            subsets[yset].parent=xset;
            subsets[xset].size=subsets[xset].size+subsets[yset].size;
        }
    }
    
    int moves[4][2]={
        {+1,0},
        {-1,0},
        {0,+1},
        {0,-1},
    };
public:
    int numEnclaves(vector<vector<int>>& A) {
        if(!A.size())
            return 0;
        int N=A.size();
        int M=A[0].size();
        
        Subset subsets[N*M];
        for(int i=0;i<N*M;i++)
            subsets[i]=Subset{i,0,1};
        int noo=0,noz=0;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(A[i][j]==1) {
                    noo++;
                    for(int k=0;k<4;k++) {
                        int nnx=i+moves[k][0];
                        int nny=j+moves[k][1];
                        
                        if(nnx>=N || nny>=M || nnx<0 || nny<0)
                            continue;
                        
                        if(A[nnx][nny]==1)
                            unite(subsets,M*i+j,M*nnx+nny);
                    }
                } else {
                    noz++;
                }
            }
        }
        
        int ans=noo;
        set<int> ugps;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(A[i][j]==1 && (i==0 || j==0 || i==N-1 || j==M-1)) {
                    ugps.insert(fp(subsets,M*i+j));
                }
            }
        }
        
        set<int>::iterator it;
        for(it=ugps.begin();it!=ugps.end();it++) {
            ans-=subsets[*it].size;
        }
        return ans;
    }
};