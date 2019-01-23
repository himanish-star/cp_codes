#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

#define ll long long

int n,m,p;

queue<pii> nextUp;

char grid[1001][1001];

ll speed[10];

int main() {
  cin>>n>>m>>p;

  for(int pid=1;pid<=p;pid++)
    cin>>speed[pid];

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      cin>>grid[i][j];
      // cout<<grid[i][j]<<" ";
    }
    // cout<<endl;
  }

  for(int pid=1;pid<=p;pid++) {
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        if(pid==grid[i][j]-48) {
          nextUp.push(mp(i,j));
        }
      }
    }
  }

  while(nextUp.size()) {
    pii curr=nextUp.front();
    int pid=grid[curr.f][curr.s]-48;
    // printf("turn of player %d\n", pid);
    nextUp.pop();

    queue<pair<int,pii> > bfs;
    bfs.push(mp(speed[pid],mp(curr.f+1,curr.s)));
    bfs.push(mp(speed[pid],mp(curr.f-1,curr.s)));
    bfs.push(mp(speed[pid],mp(curr.f,curr.s+1)));
    bfs.push(mp(speed[pid],mp(curr.f,curr.s-1)));
    while(bfs.size()) {
      pair<int,pii> intraCurr=bfs.front();
      bfs.pop();
      // printf("speedLeft: %d, x: %d, y: %d\n", intraCurr.f,intraCurr.s.f,intraCurr.s.s);
      if(intraCurr.s.f>n || intraCurr.s.s>m || intraCurr.s.f<1 || intraCurr.s.s<1) {
        continue;
      }
      if(grid[intraCurr.s.f][intraCurr.s.s]=='#' || grid[intraCurr.s.f][intraCurr.s.s]!='.') {
        continue;
      }
      if(intraCurr.f==1) {
        grid[intraCurr.s.f][intraCurr.s.s]=(char)(pid+48);
        nextUp.push(intraCurr.s);
        continue;
      }

      grid[intraCurr.s.f][intraCurr.s.s]=(char)(pid+48);
      bfs.push(mp(intraCurr.f-1,mp(intraCurr.s.f+1,intraCurr.s.s)));
      bfs.push(mp(intraCurr.f-1,mp(intraCurr.s.f-1,intraCurr.s.s)));
      bfs.push(mp(intraCurr.f-1,mp(intraCurr.s.f,intraCurr.s.s+1)));
      bfs.push(mp(intraCurr.f-1,mp(intraCurr.s.f,intraCurr.s.s-1)));
    }
  }

  for(int pid=1;pid<=p;pid++) {
    int ans=0;
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        if(pid==grid[i][j]-48) {
          ans++;
        }
      }
    }
    cout<<ans<<" ";
  }

  // while(nextUp.size()) {
  //   printf("%d,%d\n",nextUp.front().f,nextUp.front().s);
  //   nextUp.pop();
  // }
}
