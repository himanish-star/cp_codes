class Solution {
private:
    int N,M;
    int cgcolor,cucolor;
    int dir[4][2]={
        {+1,0},
        {-1,0},
        {0,+1},
        {0,-1}
    };
    
public:
    
    bool regCheck(int x,int y) {
        return (x<0 || x>=N || y<0 || y>=M);
    }
    
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &copy,vector<vector<int>> &visited,int x,int y) {
        // printf("grid[%d,%d]\n",x,y);
        grid[x][y]=cgcolor;
        visited[x][y]=1;
        for(int i=0;i<4;i++) {
            int newX=x+dir[i][0];
            int newY=y+dir[i][1];
            // cout<<N<<" "<<M<<endl;
            
            if(newX<0 || newX>=N || newY<0 || newY>=M) {
                continue;
            }
            
            if(grid[newX][newY]==cucolor && !visited[newX][newY]) {
                dfs(grid,copy,visited,newX,newY);
            }
        }
        
        int sameColor=0;
        for(int i=0;i<4;i++) {
            int newX=x+dir[i][0];
            int newY=y+dir[i][1];
            // cout<<N<<" "<<M<<endl;
            
            if(newX<0 || newX>=N || newY<0 || newY>=M) {
                continue;
            }
            
            if(copy[newX][newY]==cucolor) {
                sameColor++;
            }
        }
        
        if(sameColor==4)
            grid[x][y]=cucolor;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(!grid.size())
            return grid;
        N=grid.size();
        M=grid[0].size();
        cgcolor=color;
        cucolor=grid[r0][c0];
        
        vector<vector<int>> visited(N,vector<int> (M,0));
        vector<vector<int>> copy=grid;
        dfs(grid,copy,visited,r0,c0);
        
        return grid;
    }
};