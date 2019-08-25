#include <bits/stdc++.h> 
using namespace std; 

#define V 1000

int ans;

int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], int graph[V][V]) 
{ 
	for (int i = 1; i < V; i++) 
        if(graph[i][parent[i]]!=INT_MAX) {
            ans+=graph[i][parent[i]];
        }
} 

void primMST(int graph[V][V]) 
{ 
	int parent[V]; 
	
	int key[V]; 
	
	bool mstSet[V]; 

	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minKey(key, mstSet); 

		mstSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph); 
} 

int main() 
{ 
    int t;
    cin>>t;

    int ct=1;
    while(t--) {
        int n,m;
        cin>>n>>m;
        
        int graph[V][V];
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                graph[i][j]=INT_MAX;
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                graph[i][j]=2;
            }
        }

        for(int i=0;i<m;i++) {
            int u,v;
            cin>>u>>v;

            u--,v--;
            graph[u][v]=1;
            graph[v][u]=1;
        }
	    
        ans=0;
        primMST(graph); 
        printf("Case #%d: %d\n",ct,ans);
        ct++;

    }

	return 0; 
} 

