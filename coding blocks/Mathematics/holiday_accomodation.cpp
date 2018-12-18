#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int visited[100005];
vector<vector<pair<int,int> > > edge(100005);
vector<int> city_x_val(100005);
ll ans;

int dfs_assign(int node) {
  if(visited[node])
    return 0;
  visited[node]=1;
  // printf("$ %d $\n", node);
  for(int i=0;i<edge[node].size();i++) {

    city_x_val[node] += dfs_assign(edge[node][i].first);
  }
  // printf("$ %d city_x_val = %d$\n", node, city_x_val[node]);
  return city_x_val[node];
}

ll dfs_evaluate(int node,int n) {
  if(visited[node])
    return 0;
  visited[node]=1;
  ll local_ans = 0;
  // printf("$ %d $\n", node);
  for(int i=0;i<edge[node].size();i++) {
    if(!visited[edge[node][i].first]) {
      local_ans += dfs_evaluate(edge[node][i].first,n) + (edge[node][i].second * 2 * min(city_x_val[edge[node][i].first],n-city_x_val[edge[node][i].first]));
    }
  }
  // printf("$ %d city_x_val = %d val = %lld$\n", node, city_x_val[node], local_ans);
  return local_ans;
}

int main() {
  int t,temp;
  cin>>t;

  temp = t;
  while(t--) {
    int n;
    cin>>n;

    // make the visited array to 0
    for(int i=0;i<n;i++) {
      visited[i] = 0;
    }

    // clean vector
    for(int i=0;i<n;i++) {
      edge[i].clear();
    }

    city_x_val.clear();

    // store the edges
    for(int i=0;i<n-1;i++) {
      int x,y,z;
      cin>>x>>y>>z;

      edge[x-1].push_back(make_pair(y-1,z));
      edge[y-1].push_back(make_pair(x-1,z));
    }

    for(int i=0;i<n;i++) {
      city_x_val.push_back(1);
    }

    dfs_assign(0);

    // for(int i=0;i<n;i++) {
    //   cout<<city_x_val[i]<<" - ";
    // }
    // cout<<endl;
    ans = 0;
    for(int i=0;i<n;i++) {
      visited[i] = 0;
    }

    printf("Case #%d: %lld\n", temp-t, dfs_evaluate(0,n));
  }
  return 0;
}
