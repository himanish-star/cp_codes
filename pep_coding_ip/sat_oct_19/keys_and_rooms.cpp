class Solution {
public:
    
    set<int> roomVisit;
    
    void dfs(int u,vector<vector<int>> &rooms,vector<int> &visited) {
//         if(visited[u])
//             return;
//         visited[u]=1;
        
//         for(int i=0;i<rooms[u].size();i++) {
//             if(rooms[u][i]!=u && !visited[rooms[u][i]]) {
//                 roomVisit.insert(rooms[u][i]);
//                 dfs(rooms[u][i],rooms,visited);
//             }
//         }
//         visited[u]=0;
        
        stack<int> st;
        st.push(u);
        
        while(st.size()) {
            int e=st.top();
            st.pop();
            
            visited[e]=1;
            
            for(int i=0;i<rooms[e].size();i++) {
                if(rooms[e][i]!=e && !visited[rooms[e][i]]) {
                    roomVisit.insert(rooms[e][i]);
                    dfs(rooms[e][i],rooms,visited);
                }   
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V=rooms.size();
        
        if(!V)
            return false;
        
        roomVisit.clear();
        roomVisit.insert(0);
        vector<int> visited(V,0);
        
        dfs(0,rooms,visited);
        
        return roomVisit.size()==V;
    }
};