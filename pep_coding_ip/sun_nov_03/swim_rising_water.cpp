class Solution {
    
    struct Node {
        int x;
        int y;
    };
    
    struct Subset {
        int parent;
        int rank;
    };
    
    int moves[4][2]={
        {+1,0},
        {-1,0},
        {0,+1},
        {0,-1}
    };
    
    int find(Subset subsets[],int x) {
        if(subsets[x].parent!=x) {
            subsets[x].parent=find(subsets,subsets[x].parent);
        }
        return subsets[x].parent;
    }
    
    void unionRPC(Subset subsets[],int x,int y) {
        int xset=find(subsets,x);
        int yset=find(subsets,y);
        
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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int V=n*n;
        Subset subsets[V];
        for(int i=0;i<V;i++) {
            subsets[i]=Subset{i,0};
        }
        
        map<int,Node> valToPos;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                valToPos[grid[i][j]]=Node{i,j};
            }
        }
        
        int time=1;
        while(time<n*n) {
            // retreive node with height==time
            Node node=valToPos[time];
            
            // unite this node with surroundings
            for(int i=0;i<4;i++) {
                int nnx=node.x+moves[i][0];
                int nny=node.y+moves[i][1];
                
                if(nnx<0 || nnx>=n || nny<0 || nny>=n)
                    continue;
                
                if(grid[nnx][nny]<time)
                    unionRPC(subsets,n*nnx+nny,n*node.x+node.y);
            }
            // see if top-left and bottom-right belong to the same set
            if(find(subsets,n*0+0)==find(subsets,n*(n-1)+n-1)) {
                return time;
            }
            time++;
        }
        return time;
    }
};