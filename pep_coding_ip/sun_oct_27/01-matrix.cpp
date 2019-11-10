#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Coord {
        int x;
        int y;
    };
    
    int dir[4][2] = {
        {+1,0},  
        {-1,0},  
        {0,+1},  
        {0,-1}  
    };
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        if(!matrix.size())
            return matrix;
        
        vector<vector<int>> updatedMatrix = matrix;
        
        vector<vector<int>> visited(matrix.size(),vector<int> (matrix[0].size(),0));
        queue<Coord> qu;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j]==1)
                    updatedMatrix[i][j]=INT_MAX;
                else
                    qu.push(Coord{i,j});
            }
        }
        
        int level=-1;
        while(qu.size()) {
            level++;
            int count=qu.size();
            while(count--) {
                Coord p=qu.front();
                qu.pop();
                                
                updatedMatrix[p.x][p.y]=min(updatedMatrix[p.x][p.y],level);
                for(int i=0;i<4;i++) {
                    int nx=p.x+dir[i][0];
                    int ny=p.y+dir[i][1];
                    
                    if(nx<0 || ny<0 || nx>=matrix.size() || ny>=matrix[0].size())
                        continue;
                    
                    if(updatedMatrix[p.x][p.y]+1<updatedMatrix[nx][ny])
                        qu.push(Coord{nx,ny});
                }
            }
        }
        
        return updatedMatrix;
    }
};