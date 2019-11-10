#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    struct Subset {
        int parent;
        int rank;
    };
    
    int find(Subset subsets[],int i) {
        if(subsets[i].parent!=i) {
            subsets[i].parent=find(subsets,subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void unionByRank(Subset subsets[],int x,int y) {
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
    
    void dfs(int x,int y,vector<int>& visited,vector<vector<char>>& grid,Subset subsets[]) {
        int N=grid.size();
        int M=grid[0].size();
        
        if(x<0 || x>=N || y<0 || y>=M)
            return;
        
        // cout<<x<<y<<endl;
        
        visited[M*x+y]=1;
        
        if(x+1<N && grid[x+1][y]=='1' && !visited[M*(x+1)+y]) {
            unionByRank(subsets,M*x+y,M*(x+1)+y);
            dfs(x+1,y,visited,grid,subsets);
        } 
        
        if(x-1>=0 && grid[x-1][y]=='1' && !visited[M*(x-1)+y]) {
            unionByRank(subsets,M*x+y,M*(x-1)+y);
            dfs(x-1,y,visited,grid,subsets);
        }
        
        if(y+1<M && grid[x][y+1]=='1' && !visited[M*x+(y+1)]) {
            unionByRank(subsets,M*x+y,M*x+(y+1));
            dfs(x,y+1,visited,grid,subsets);
        }
        
        if(y-1>=0 && grid[x][y-1]=='1' && !visited[M*x+(y-1)]) {
            unionByRank(subsets,M*x+y,M*x+(y-1));
            dfs(x,y-1,visited,grid,subsets);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(!grid.size())
            return 0;
        
        int N=grid.size();
        int M=grid[0].size();
        
        int V=N*M;
        
        Subset *subsets=new Subset[V];
        int sub=0;
        for(int i=0;i<V;i++) {
            subsets[i].parent=i;
            subsets[i].rank=0;
        }
        
        vector<int> visited(V,0);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                int idx=M*i+j;
                if(!visited[idx] && grid[i][j]=='1') {
                    // cout<<"as"<<endl;
                    dfs(i,j,visited,grid,subsets);
                } else if(grid[i][j]=='0')
                    sub++;
            }
        }
        
        set<int> s;
        for(int i=0;i<V;i++)
            s.insert(subsets[i].parent);
        
        return s.size()-sub;
    }
};