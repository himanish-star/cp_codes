class Solution {
    struct Subset {
        int parent;
        int rank;
    };
    
    int find(Subset subsets[],int i) {
        if(i!=subsets[i].parent) {
            subsets[i].parent=find(subsets,subsets[i].parent);
        }
        return subsets[i].parent;
    }
    
    void unite(Subset subsets[],int x,int y) {
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
    int longestConsecutive(vector<int>& numsOrg) {
        if(numsOrg.size()==0)
            return 0;
        
        set<int> s;
        vector<int> nums;
        for(int i=0;i<numsOrg.size();i++)
            s.insert(numsOrg[i]);
        
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++) {
            nums.push_back(*it);
        }
        
        
        Subset subsets[nums.size()];
        
        map<int,int> valToIdx;
        map<int,int> sizeOfSets;
        for(int i=0;i<nums.size();i++) {
            valToIdx[nums[i]]=i;
            subsets[i]=Subset{i,0};
            sizeOfSets[nums[i]]=1;
        }
        
        int ans=1;
        for(int i=0;i<nums.size();i++) {
            
            if(valToIdx.find(nums[i]+1)!=valToIdx.end() && find(subsets,valToIdx[nums[i]])!=find(subsets,valToIdx[nums[i]+1])) {
                int sz1=sizeOfSets[nums[find(subsets,valToIdx[nums[i]])]];
                int sz2=sizeOfSets[nums[find(subsets,valToIdx[nums[i]+1])]];
                
                unite(subsets,valToIdx[nums[i]],valToIdx[nums[i]+1]);
                
                int newSize=sz1 + sz2;
                sizeOfSets[nums[find(subsets,valToIdx[nums[i]])]]=newSize;
                
                ans=max(ans,newSize);

            }
            
            if(valToIdx.find(nums[i]-1)!=valToIdx.end() && find(subsets,valToIdx[nums[i]])!=find(subsets,valToIdx[nums[i]-1])) {
                int sz1=sizeOfSets[nums[find(subsets,valToIdx[nums[i]])]];
                int sz2=sizeOfSets[nums[find(subsets,valToIdx[nums[i]-1])]];
                
                unite(subsets,valToIdx[nums[i]],valToIdx[nums[i]-1]);
                
                int newSize=sz1 + sz2;
                sizeOfSets[nums[find(subsets,valToIdx[nums[i]])]]=newSize;
                
                ans=max(ans,newSize);
            }
        }
        return ans;
    }
};