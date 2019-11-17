#include<bits/stdc++.h>

using namespace std;

class Solution {
    struct Node {
        string str;
        int swaps;
        int idx;
    };
public:
    int kSimilarity(string A, string B) {
        queue<Node> qu;
        qu.push(Node{B,0,0});
        
        map<string,int> vis;
        while(qu.size()) {
            int count=qu.size();
            while(count--) {
                Node node=qu.front();
                qu.pop();
                
                if(vis[node.str])
                    continue;
                
                if(node.str==A)
                    return node.swaps;
                
                vis[node.str]=1;
                int idx=node.idx;
                while(A[idx]==node.str[idx]) {
                    idx++;
                }
                
                for(int i=idx;i<node.str.size();i++) {
                    if(A[idx]==node.str[i]) {
                        node.str[i]=node.str[idx];
                        node.str[idx]=A[idx];
                        
                        node.swaps++;
                        
                        if(!vis[node.str]) {
                            qu.push(node);
                        }
                        
                        node.swaps--;
                        
                        node.str[idx]=node.str[i];
                        node.str[i]=A[idx];
                    }
                }
            }
        }
        return -1;
    }
};