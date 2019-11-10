class Solution {
public:
    
    int N,M;
    
    void bfs(int x,int y,vector<vector<int>> grid,vector<bool> visited,vector<int> &minTime) {
        queue<pair<int,int>> qu;
        
        int level=-1;
        qu.push(make_pair(x,y));
        while(qu.size()) {
            level++;
            int count=qu.size();
            while(count--) {
                pair<int,int> p=qu.front();
                qu.pop();
                
                visited[M*p.first+p.second]=true;
                minTime[M*p.first+p.second]=min(minTime[M*p.first+p.second],level);
                
                if(p.first+1<N && grid[p.first+1][p.second]==1 && !visited[M*(p.first+1)+p.second]) {
                    qu.push(make_pair(p.first+1,p.second));
                }
                
                if(p.first-1>=0 && grid[p.first-1][p.second]==1 && !visited[M*(p.first-1)+p.second]) {
                    qu.push(make_pair(p.first-1,p.second));
                }
                
                if(p.second+1<M && grid[p.first][p.second+1]==1 && !visited[M*p.first+p.second+1]) {
                    qu.push(make_pair(p.first,p.second+1));
                }
                
                if(p.second-1>=0 && grid[p.first][p.second-1]==1 && !visited[M*p.first+p.second-1]) {
                    qu.push(make_pair(p.first,p.second-1));
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        
        N=grid.size();
        M=grid[0].size();
        
        vector<bool> visited(N*M,false);
        vector<int> minTime(N*M,INT_MAX);
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(!visited[M*i+j] && grid[i][j]==2) {
                    bfs(i,j,grid,visited,minTime);
                }
            }
        }
        
        int max_time=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(minTime[M*i+j]==INT_MAX && grid[i][j]==1)
                    return -1;
                else if(grid[i][j]==1)
                    max_time=max(max_time,minTime[M*i+j]);
                
            }
        }
        return max_time;
    }
};