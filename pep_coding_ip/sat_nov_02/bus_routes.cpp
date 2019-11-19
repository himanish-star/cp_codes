class Solution {
    struct Node {
        vector<int> arr;
        int key;
        int level;
    };
public:
    
    int bfs(Node start,vector<vector<int>>& routes,int T,map<int,Node> &mn,map<int,vector<int>> &sb) {
        // cout<<"NewBFS\n"<<endl<<endl;
        queue<Node> qu;
        qu.push(start);
        
        vector<int> levels_arr(routes.size()+1);
        levels_arr[start.key]=1;
        
        int level=-1;
        vector<int> visited(routes.size()+1);
        set<int> ans;
        while(qu.size()) {
            int count=qu.size();
            level++;
            while(count--) {
                Node node=qu.front();
                qu.pop();
                
                if(visited[node.key])
                    continue;
                
                // cout<<"Bus:"<<node.key<<endl;
                visited[node.key]=1;
                ans.insert(node.key);
                
                for(int i=0;i<node.arr.size();i++) {
                    if(node.arr[i]==T) {
                        return levels_arr[node.key];
                    }
                }
                
                for(int i=0;i<node.arr.size();i++) {
                    for(int j=0;j<sb[node.arr[i]].size();j++) {
                        if(!visited[sb[node.arr[i]][j]]) {
                            // cout<<"change at stop:"<<node.arr[i]<<", to bus:"<<sb[node.arr[i]][j]<<endl;
                            if(levels_arr[mn[sb[node.arr[i]][j]].key])
                            levels_arr[mn[sb[node.arr[i]][j]].key]=min(levels_arr[mn[sb[node.arr[i]][j]].key],1+levels_arr[node.key]);
                            else
                                levels_arr[mn[sb[node.arr[i]][j]].key]=1+levels_arr[node.key];
                            qu.push(mn[sb[node.arr[i]][j]]);
                        }
                    }
                }
            }
        }
        return INT_MAX;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int,Node> mn;
        map<int,vector<int>> sb;
        
        vector<Node> qu;
        
        for(int i=0;i<routes.size();i++) {
            vector<int> newVal;
            set<int> nn;
            for(int j=0;j<routes[i].size();j++) {
                nn.insert(routes[i][j]);
            }
            set<int>::iterator it;
            for(it=nn.begin();it!=nn.end();it++)
                newVal.push_back(*it);
            routes[i]=newVal;
        }
        
        
        for(int i=0;i<routes.size();i++) {
            mn.insert(make_pair(i+1,Node{routes[i],i+1,1}));
            for(int j=0;j<routes[i].size();j++) {
                if(routes[i][j]==S)
                    qu.push_back(mn[i+1]);
                
                if(routes[i][j]==S && routes[i][j]==T)
                    return 0;
                
                if(sb.find(routes[i][j])==sb.end()) {
                    vector<int> adj;
                    adj.push_back(i+1);
                    sb[routes[i][j]]=adj;
                } else {
                    sb[routes[i][j]].push_back(i+1);
                }
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<qu.size();i++) {
            // cout<<"call"<<endl;
            ans=min(ans,bfs(qu[i],routes,T,mn,sb));
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};