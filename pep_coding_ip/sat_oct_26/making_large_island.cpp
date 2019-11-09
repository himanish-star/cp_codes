class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &group,int x,int y,int grpid,int &noOfMembers) {
        int n=group.size();
        int m=group[0].size();
        
        if(x<0 || x>=n || y<0 || y>=m)
            return;
        
        if(grid[x][y]==0)
            return;
        
        if(group[x][y])
            return;
        
        // cout<<x<<":"<<y<<endl;
        group[x][y]=grpid;
        noOfMembers++;
        
        dfs(grid,group,x+1,y,grpid,noOfMembers);
        dfs(grid,group,x-1,y,grpid,noOfMembers);
        dfs(grid,group,x,y+1,grpid,noOfMembers);
        dfs(grid,group,x,y-1,grpid,noOfMembers);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        if(!grid.size())
            return 0;
        
        vector<vector<int>> group(grid.size(),vector<int> (grid[0].size(),0));
        
        int grpid=1;
        map<int,int> grpMem;
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(!group[i][j] && grid[i][j]) {
                    int noOfMembers=0;
                    dfs(grid,group,i,j,grpid,noOfMembers);
                    grpMem[grpid]=noOfMembers;
                    grpid++;
                    ans=max(ans,noOfMembers);
                }
            }
        }
        
        int n=group.size();
        int m=group[0].size();
        
        // for(int i=0;i<grid.size();i++) {
        //     for(int j=0;j<grid[0].size();j++) {
        //         cout<<group[i][j]<<"["<<grpMem[group[i][j]]<<"]";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                
                if(grid[i][j]==0) {
                    set<int> nbrs;
                    if(i+1<n && grid[i+1][j]==1) {
                        nbrs.insert(group[i+1][j]);
                    }
                    if(i-1>=0 && grid[i-1][j]==1) {
                        nbrs.insert(group[i-1][j]);
                    }
                    if(j+1<m && grid[i][j+1]==1) {
                        nbrs.insert(group[i][j+1]);
                    }
                    if(j-1>=0 && grid[i][j-1]==1) {
                        nbrs.insert(group[i][j-1]);
                    }
                    
                    set<int>::iterator it;
                    int tempAns=0;
                    for(it=nbrs.begin();it!=nbrs.end();it++) {
                        tempAns+=grpMem[*it];
                    }
                    ans=max(ans,1+tempAns);
                }
            }
        }
        return ans;
    }
};
