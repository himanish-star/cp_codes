class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int count=0;
        
        int d[9][2] = {
            {0,0},  
            {-1,-1},  
            {+1,+1},  
            {+1,-1},  
            {-1,+1},  
            {-1,0},  
            {+1,0},  
            {0,-1},  
            {0,+1}  
        };
        
        for(int i=1;i<g.size()-1;i++) {
            for(int j=1;j<g[0].size()-1;j++) {
                
                set<int> s;
                for(int k=0;k<9;k++) {
                    int val=g[i+d[k][0]][j+d[k][1]];
                    if(val>=1 && val<=9)
                        s.insert(val);
                }
                
                if(s.size()==9 && g[i][j]+g[i+1][j+1]+g[i-1][j-1]==15 && 
                  g[i][j]+g[i+1][j-1]+g[i-1][j+1]==15 &&
                  g[i-1][j]+g[i-1][j+1]+g[i-1][j-1]==15 &&
                  g[i][j]+g[i][j+1]+g[i][j-1]==15 &&
                  g[i+1][j]+g[i+1][j+1]+g[i+1][j-1]==15 &&
                  g[i-1][j-1]+g[i][j-1]+g[i+1][j-1]==15 &&
                  g[i-1][j]+g[i][j]+g[i+1][j]==15 &&
                  g[i][j+1]+g[i+1][j+1]+g[i-1][j+1]==15)
                    count++;
            }
        }
        
        return count;
    }
};