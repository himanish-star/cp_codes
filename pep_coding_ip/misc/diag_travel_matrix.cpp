class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(!matrix.size())
            return res;
        
        int n=matrix.size(), m=matrix[0].size();
        vector<deque<int>> trv(n+m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                trv[i+j].push_back(matrix[i][j]);
            }
        }
        int turn=0;
        for(int i=0;i<trv.size();i++) {
            if(turn%2) {
                while(trv[i].size()) {
                    res.push_back(trv[i].front());
                    trv[i].pop_front();
                }
            } else {
                while(trv[i].size()) {
                    res.push_back(trv[i].back());
                    trv[i].pop_back();
                }
            }
            turn++;
        }
        
        return res;
    }
};