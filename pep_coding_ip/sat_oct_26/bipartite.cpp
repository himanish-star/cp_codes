struct Node {
    int parent;
    int rank;
};

bool isCycle(int adj[][MAX],int V) {
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            if(adj[i][j] && i==j) {
                return true;
            }
        }
    }
    return false;
}

bool isBipartite(int adj[][MAX],int V)
{
     
     if(isCycle(adj,V))
        return false;
     
     queue<int> qu;
     qu.push(0);
     
     int color=0;
     vector<int> visited(V,0);
     vector<int> colorArr(V,0);
     while(qu.size()) {
         int count=qu.size();
         
         while(count--) {
             int node=qu.front();
             qu.pop();
             
             if(visited[node]) {
                if(color!=colorArr[node]) {
                    // printf("\n%d expected | got %d for node %d\n",colorArr[node],color,node);
                    return false;
                }
                continue;
             }
             
            //  printf("\nnew node: %d colored with color: %d\n",node,color);
             visited[node]=1;
             colorArr[node]=color;
             for(int i=0;i<V;i++) {
                 if(adj[node][i]) {
                    //  printf("[adj node:%d]",i);
                     qu.push(i);
                 }
             }
         }
         
         color=(color+1)%2;
     }
     return true;
}