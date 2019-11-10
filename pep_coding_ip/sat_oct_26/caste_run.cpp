#include<bits/stdc++.h>

using namespace std;

bool wayPossible;

set<int> visited;

void dfs(vector<vector<int>> &grid,int src) {
    
    bool canMove=false;
    visited.insert(src);
    // printf("Room being visited: %d\n",src);
    for(int i=0;i<grid[0].size();i++) {
        if(grid[src][i]==1) {
            // path is usable
            grid[src][i]=-1;
            grid[i][src]=-1;
            canMove=true;
            dfs(grid,i);
        }
    }
    if(!canMove) {
        if(src!=0 || visited.size()!=grid.size()) {
            wayPossible=false;
        }
    }
}

int main() {
    int test_cases;
    cin>>test_cases;
    
    while(test_cases--) {
        int n;
        cin>>n;
        
        vector<vector<int>> grid(n,vector<int> (n,-1));
        
        bool isThereAOne=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>grid[i][j];
                if(grid[i][j]==1)
                    isThereAOne=true;
            }
        }
        
        if(n==1) {
            cout<<"True"<<endl;
            continue;
        }
        
        if(!isThereAOne) {
            cout<<"False"<<endl;
            continue;
        }
        
        wayPossible=true;
        visited.clear();
        dfs(grid,0);
        
        if(visited.size()!=n) {
            cout<<"False"<<endl;
            continue;
        }
        
        // if(wayPossible) {
        //     for(int i=0;i<n;i++) {
        //         for(int j=0;j<n;j++) {
        //             cout<<grid[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        
        wayPossible ? cout<<"True"<<endl : cout<<"False"<<endl;
    }
    return 0;
}