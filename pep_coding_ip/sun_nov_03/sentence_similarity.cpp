class Solution {
private:
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
public:
    /**
     * @param words1: 
     * @param words2: 
     * @param pairs: 
     * @return: Whether sentences are similary or not?
     */
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        // 
        
        if(words2.size() != words1.size())
            return false;
        
        set<string> uw;
        for(int i=0;i<words1.size();i++) {
            uw.insert(words1[i]);
            uw.insert(words2[i]);
        }
        
        for(int i=0;i<pairs.size();i++) {
            uw.insert(pairs[i][0]);
            uw.insert(pairs[i][1]);
        }
        
        set<string>::iterator it;
        int idx;
        map<string,int> wtoi;
        Subset subsets[uw.size()];
        for(idx=0,it=uw.begin();it!=uw.end();idx++,it++) {
            wtoi.insert(make_pair(*it,idx));
            subsets[idx]=Subset{idx,0};
        }
        
        for(int i=0;i<pairs.size();i++) {
            string w1=pairs[i][0];
            string w2=pairs[i][1];
            
            if(fp(subsets,wtoi[w1])!=fp(subsets,wtoi[w2]))
                unite(subsets,wtoi[w1],wtoi[w2]);
        }
        
        
        vector<int> id1,id2;
        for(int i=0;i<words2.size();i++) {
            id1.push_back(fp(subsets,wtoi[words1[i]]));
            id2.push_back(fp(subsets,wtoi[words2[i]]));
        }
        
        return id1==id2;
    }
};