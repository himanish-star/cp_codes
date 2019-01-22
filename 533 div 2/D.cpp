#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,p;

ll noCastles[10]={0};

int speed[10];

ll totalUsed=0;

char grid[1001][1001];
int vis[1001][1001];

void travel(int p,int movesLeft,int x,int y) {
    if(x>n || y>m || x<1 || y<1)
        return;

    if(vis[x][y])
        return;

    if(grid[x][y]=='#')
        return;

    if(grid[x][y]!='.')
        return;

    if(!movesLeft)
        return;

    vis[x][y]=1;
    totalUsed--;
    // cout<<x<<','<<y<<":->"<<totalUsed<<endl;
    grid[x][y]=(char)(p+'0');
    // cout<<(char)(p+'0')<<" ";
    travel(p,movesLeft-1,x+1,y);
    travel(p,movesLeft-1,x-1,y);
    travel(p,movesLeft-1,x,y+1);
    travel(p,movesLeft-1,x,y-1);
    return;
}

int main() {
  cin>>n>>m>>p;

  for(int i=1;i<=p;i++)
    cin>>speed[i];

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      cin>>grid[i][j];
      if(grid[i][j]=='.')
        totalUsed++;
    }
  }


  int turn=0;
  int check=10;
  while(totalUsed) {
    // printf("%d turn\n", ++turn);
    memset(vis,0,sizeof(vis));
    for(int pp=1;pp<=p;pp++)
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        if(!vis[i][j] && grid[i][j]!='.' && grid[i][j]!='#') {
          int pid=grid[i][j]-48;
        //   cout<<pid<<endl;
          if(pp!=pid)
            continue;
          travel(pid,speed[pid],i+1,j);
          travel(pid,speed[pid],i-1,j);
          travel(pid,speed[pid],i,j+1);
          travel(pid,speed[pid],i,j-1);
        }
      }
    }

    // for(int i=1;i<=n;i++) {
    //   for(int j=1;j<=m;j++) {
    //     printf("%c ", grid[i][j]);
    //   }
    //   cout<<endl;
    // }
  }

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
        if(grid[i][j]!='.' && grid[i][j]!='#') {
          int pid=grid[i][j]-48;
          noCastles[pid]++;
        }
    }
  }

  for(int i=1;i<=p;i++) {
    cout<<noCastles[i]<<" ";
  }

  return 0;
}
