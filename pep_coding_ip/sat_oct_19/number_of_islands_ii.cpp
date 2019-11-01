/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    
    int noOfIslands, noOfLands;
    
    // vector<int> converted;
    
    struct Subset {
        int parent;
        int rank;
    };
    
    int find(Subset subsets[],int i) {
        if(i!=subsets[i].parent)
            subsets[i].parent = find(subsets,subsets[i].parent);
        return subsets[i].parent;
    }
    
    
    void unionRPC(Subset subsets[],int x,int y) {
        int xset=find(subsets,x);
        int yset=find(subsets,y);
        
        if(subsets[xset].rank>subsets[yset].rank) {
            subsets[yset].parent = xset;
        } else if(subsets[xset].rank<subsets[yset].rank) {
            subsets[xset].parent = yset;
        } else {
            subsets[xset].rank++;
            subsets[yset].parent = xset;
        }
    }
    
    void connect(int x,int y,Subset subsets[],int &n,int &m,vector<vector<int>> &grid) {
        noOfIslands++;
        grid[x][y]=1;
        
        if(x+1<n && grid[x+1][y]==1) {
            int xset=find(subsets,m*x+y);
            int yset=find(subsets,m*(x+1)+y);
            
            if(xset!=yset) {
                unionRPC(subsets,xset,yset);
                noOfIslands--;
            }
        }
        
        if(x-1>=0 && grid[x-1][y]==1) {
            int xset=find(subsets,m*x+y);
            int yset=find(subsets,m*(x-1)+y);
            
            if(xset!=yset) {
                unionRPC(subsets,xset,yset);
                noOfIslands--;
            }
        }
        
        if(y+1<m && grid[x][y+1]==1) {
            int xset=find(subsets,m*x+y);
            int yset=find(subsets,m*x+y+1);
            
            if(xset!=yset) {
                unionRPC(subsets,xset,yset);
                noOfIslands--;
            }
        }
        
        if(y-1>=0 && grid[x][y-1]==1) {
            int xset=find(subsets,m*x+y);
            int yset=find(subsets,m*x+y-1);
            
            if(xset!=yset) {
                unionRPC(subsets,xset,yset);
                noOfIslands--;
            }
        }
    }
    
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        int V=n*m;
        noOfIslands=0;
        Subset *subsets = new Subset[V];
        for(int i=0;i<V;i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
        
        vector<vector<int>> grid(n,vector<int> (m,0));
          
        vector<int> result;
        // converted.clear();
        // for(int i=0;i<V;i++) converted.push_back(0);
        for(int i=0;i<operators.size();i++) {
            int x=operators[i].x;
            int y=operators[i].y;
            
            if(!grid[x][y])
                connect(x,y,subsets,n,m,grid);
            
            result.push_back(noOfIslands);
        }
        
        for(int i=0;i<V;i++) {
            cout<<subsets[i].parent<<" ";
        }
        
        return result;
    }
};