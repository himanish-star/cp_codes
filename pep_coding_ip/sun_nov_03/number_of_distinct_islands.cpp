class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
     
    int moves[4][2]={
        {+1,0},
        {-1,0},
        {0,+1},
        {0,-1}
    };
     
    void dfs(int x,int y,int &refx,int &refy,vector<vector<int>> &grid,vector<vector<int>> &visited,vector<pair<int,int>> &cf) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(x>=n || y>=m || x<0 || y<0) {
            return;
        }
        
        if(visited[x][y]==1)
            return;
        
        if(grid[x][y]!=1)
            return;
        
        visited[x][y]=1;
        cf.push_back(make_pair(x-refx,y-refy));
        
        for(int i=0;i<4;i++) {
            int nnx=x+moves[i][0];
            int nny=y+moves[i][1];
            
            dfs(nnx,nny,refx,refy,grid,visited,cf);
        }
    }
    
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        if(!grid.size())
            return 0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));
        set<vector<pair<int,int>>> uc;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    vector<pair<int,int>> cf;
                    dfs(i,j,i,j,grid,visited,cf);
                    cout<<"United: ";
                    for(int it=0;it<cf.size();it++)
                        cout<<cf[it].first<<","<<cf[it].second<<" ";
                    cout<<endl;
                    uc.insert(cf);
                }
            }
        }
        
        return uc.size();
    }
};