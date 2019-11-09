bool Graph::isConnected() 
{
    vector<int> visited(V,0);
    
    queue<int> qu;
    qu.push(0);
    
    while(qu.size()) {
        int count=qu.size();
        while(count--) {
            int e=qu.front();
            qu.pop();
            visited[e]=1;
            
            list<int>::iterator i; 
            
            if(!adj[e].size())
                continue;
            
            for(i=adj[e].begin();i!=adj[e].end();i++) {
                int v=*i;
                if(!visited[v])
                    qu.push(v);
            }
        }
    }
    
    bool connected=true;
    for(int i=0;i<V;i++) {
        if(!visited[i])
            connected=false;
    }
    return connected;
}
int Graph::isEulerian()
{
    if(!isConnected())
        return 0;
        
    int odd=0;
    vector<int> indeg(V,0);
    for(int i=0;i<V;i++) {
        list<int>::iterator j; 
        for(j=adj[i].begin();j!=adj[i].end();j++) {
            indeg[*j]++;
        }
    }
    
    for(int i=0;i<V;i++) {
        if(indeg[i]%2)
            odd++;
    }
    
    if(odd>2)
        return 0;
    
    return (odd) ? 1:2;
}