class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(!trust.size()) {
            return 1;
        }
        
        vector<int> outdeg(N,0);
        vector<int> indeg(N,0);
        vector<int> candidates;
        for(int i=0;i<trust.size();i++) {
            outdeg[trust[i][0]-1]++;
            indeg[trust[i][1]-1]++;
        }
        
        for(int i=0;i<N;i++) {
            cout<<outdeg[i]<<" ";
            if(!outdeg[i])
                candidates.push_back(i+1);
        }
        cout<<endl;
        
        if(candidates.size()==1 && indeg[candidates[0]-1]==N-1) {
            return candidates[0];
        }
        
        return -1;
    }
};