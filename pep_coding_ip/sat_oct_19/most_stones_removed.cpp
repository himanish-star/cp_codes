class Solution {
private:
    struct Subset {
        int rank;
        int parent;
    };   
public:
    
    int find(map<int,Subset> &subsets,int i) {
        if(i!=subsets[i].parent) {
            subsets[i].parent = find(subsets,subsets[i].parent);
        }
        return subsets[i].parent;
    }
    
    void unionRPC(map<int,Subset> &subsets,int x,int y) {
        int xset=find(subsets,x);
        int yset=find(subsets,y);
        
        if(subsets[xset].rank>subsets[yset].rank) {
            subsets[yset].parent = xset;
        } else if(subsets[xset].rank<subsets[yset].rank) {
            subsets[xset].parent = yset;
        } else {
            subsets[yset].rank++;
            subsets[xset].parent = yset;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int maxIdx=0;
        for(int i=0;i<stones.size();i++) {
            maxIdx=max(maxIdx,stones[i][0]);
            maxIdx=max(maxIdx,stones[i][1]);
        }
        
        map<int,Subset> subsets;
        for(int i=-(maxIdx+1);i<=maxIdx;i++) {
            subsets.insert(make_pair(i,Subset{0,i}));
        }
        
        
        for(int i=0;i<stones.size();i++) {
            int x=stones[i][0];
            int y=-1-stones[i][1];
            
            int xp=find(subsets,x);
            int yp=find(subsets,y);
            
            if(xp!=yp)
                unionRPC(subsets,xp,yp);
        }
        
        set<int> uniqueGrps;
        for(int i=0;i<stones.size();i++) {
            uniqueGrps.insert(find(subsets,stones[i][0]));
        }
        
        return stones.size()-uniqueGrps.size();
    }
};