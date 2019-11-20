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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        if(!edges.size())
            return result;
        
        int max_node_idx=0;
        for(int i=0;i<edges.size();i++) {
            max_node_idx=max(max_node_idx,edges[i][0]);
            max_node_idx=max(max_node_idx,edges[i][1]);
        }
        
        Subset subsets[max_node_idx+1];
        for(int i=0;i<max_node_idx+1;i++) {
            subsets[i]=Subset{i,0};
        }
        
        for(int i=0;i<edges.size();i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(fp(subsets,u)!=fp(subsets,v)) {
                unite(subsets,u,v);
            } else {
                return edges[i];
            }
        }
        
        return result;
    }
};