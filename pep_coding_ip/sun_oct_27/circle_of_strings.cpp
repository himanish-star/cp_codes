#include<bits/stdc++.h>
using namespace std;

bool ringForms;
int startLetter;

void dfs(int u,int v,vector<vector<int>> &adj,int n,int depth) {
    // printf("edge %c->%c\n",u+'a',v+'a');
    adj[u][v]--;
    bool newPath=false;
    for(int i=0;i<26;i++) {
        if(adj[v][i]) {
            newPath=true;
            dfs(v,i,adj,n,depth+1);
        }
    }
    if(!newPath && depth+1==n) {
        ringForms = bool(startLetter==v);
    }
    adj[u][v]++;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    
	    vector<vector<int>> adj(26,vector<int> (26,0));
	    int x,y;
	    vector<string> words;
	    for(int i=0;i<n;i++) {
	        string word;
	        cin>>word;
	        words.push_back(word);
	        int u=word[0]-'a';
	        int v=word[word.size()-1]-'a';
	       // cout<<u<<" "<<v<<endl;
	        adj[u][v]++;
	        x=u;
	        y=v;
	    }
	    
	    ringForms=false;
	    startLetter = x;
        // cout<<endl;
        dfs(x,y,adj,n,0);
	    
	   // if(ddepth==n)
	   //     ringForms=true;
	    
	    if(n==1 && words[0][0]==words[0][words[0].size()-1])
	        ringForms=true;
	    cout<<ringForms<<endl;
	}
	return 0;
}