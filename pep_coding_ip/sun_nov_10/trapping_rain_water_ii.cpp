#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int n=heightMap.size();
        
        if(!n)
            return 0;
        
        int m=heightMap[0].size();
        map<int,int> seen;
        for(int i=0;i<n;i++) {
            pq.push(make_pair(heightMap[i][0],make_pair(i,0)));
            pq.push(make_pair(heightMap[i][m-1],make_pair(i,m-1)));
            seen[i*m+0]=1;
            seen[i*m+m-1]=1;
            
            // printf("put to boundary %d,%d --> height: %d\n",i,0,heightMap[i][0]);
            // printf("put to boundary %d,%d --> height: %d\n",i,m-1,heightMap[i][m-1]);
        }
        
        for(int i=1;i<m-1;i++) {
            pq.push(make_pair(heightMap[0][i],make_pair(0,i)));
            pq.push(make_pair(heightMap[n-1][i],make_pair(n-1,i)));
            seen[0*m+i]=1;
            seen[(n-1)*m+i]=1;
            
            // printf("put to boundary %d,%d --> height: %d\n",0,i,heightMap[0][i]);
            // printf("put to boundary %d,%d --> height: %d\n",n-1,i,heightMap[n-1][i]);
        }
        
        
        int water=0;
        while(pq.size()) {
            pair<int,pair<int,int>> top=pq.top();
            pq.pop();
            
            int dir[4][2]={
                {+1,0},
                {-1,0},
                {0,+1},
                {0,-1},
            };
            
            // printf("select boundary %d,%d --> height: %d\n",top.second.first,top.second.second,top.first);
            
            for(int i=0;i<4;i++) {
                int nnx=dir[i][0]+top.second.first;
                int nny=dir[i][1]+top.second.second;
                
                if(nnx>=n || nny>=m || nnx<0 || nny<0)
                    continue;
                
                if(!seen[nnx*m+nny] && heightMap[nnx][nny]>=top.first) {
                    //include nnx,nny as the new boundary
                    pq.push(make_pair(heightMap[nnx][nny],make_pair(nnx,nny)));
                    seen[nnx*m+nny]=1;
                } else {
                    if(!seen[nnx*m+nny]) {
                        // printf("%d,%d --> water: %d\n",nnx,nny,top.first-heightMap[nnx][nny]);
                        water += top.first-heightMap[nnx][nny];
                        seen[nnx*m+nny]=1;
                        pq.push(make_pair(top.first,make_pair(nnx,nny)));
                    }
                }
            }
        }
        return water;
    }
};