class Solution {
    struct Position {
        int x,y;
        int getPos() {
            return 3*x+y;
        }
    };
    
    struct Node {
        string b;
        Position p;
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string tb="123450";
        
        queue<Node> qu;
        Node node;
        
        string ib;
        Position ip;
        
        //search for 0 in the initial board
        for(int i=0;i<2;i++) {
            for(int j=0;j<3;j++) {
                ib.push_back(char(board[i][j]+48));
                if(board[i][j]==0) {
                    ip = Position{i,j};
                }
            }
        }
        node = Node{ib,ip};
        qu.push(node);
        
        int level=-1;
        map<string,int> seen;
        
        int m[4][2] = {
            {+1,0},
            {-1,0},
            {0,+1},
            {0,-1}
        };
        while(qu.size()) {
            int ct=qu.size();
            level++;
            while(ct--) {
                Node front = qu.front();
                qu.pop();
                
                seen[front.b]=1;
                
                if(front.b==tb)
                    return level;
                
                for(int i=0;i<4;i++) {
                    int nnx=m[i][0]+front.p.x;
                    int nny=m[i][1]+front.p.y;
                    
                    if(nnx>=2 || nny>=3 || nnx<0 || nny<0)
                        continue;
                    
                    string nb=front.b;
                    char temp=nb[front.p.getPos()];
                    nb[front.p.getPos()]=nb[3*nnx+nny];
                    nb[3*nnx+nny]=temp;
                    
                    if(!seen[nb])
                        qu.push(Node{nb,Position{nnx,nny}});
                }
            }
        }
        
        return -1;
    }
};