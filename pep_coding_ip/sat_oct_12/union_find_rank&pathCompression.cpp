#include<bits/stdc++.h>

using namespace std;

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

void unionFunc(Subset subsets[],int x,int y) {
    int xset=find(subsets,x);
    int yset=find(subsets,y);
    
    if(subsets[xset].rank<subsets[yset].rank) {
        subsets[xset].parent=yset;
    } else if(subsets[xset].rank>subsets[yset].rank) {
        subsets[yset].parent=xset;
    } else {
        subsets[xset].rank++;
        subsets[yset].parent=xset;
    }
}

bool isCyclic(vector<int> adjo[], int V)
{
    Subset subsets[V];
    vector<int> adj[V];
    
    for(int i=0;i<V;i++) {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<adjo[i].size();j++) {
            if(i<=adjo[i][j]) {
                // cout<<i<<" "<<adjo[i][j]<<endl;
                adj[i].push_back(adjo[i][j]);
            }
        }
    }
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<adj[i].size();j++) {
            // cout<<i<<" "<<adj[i][j]<<endl;
            int x=find(subsets,i);
            int y=find(subsets,adj[i][j]);
            
            if(x==y) {
                // printf("%d[%d]:%d[%d]\n",i,x,adj[i][j],y);
                // cout<<i<<prinx]<<":"<<y<<endl;
                return true;
            } else
                unionFunc(subsets,x,y);
        }
    }
    return false;
}