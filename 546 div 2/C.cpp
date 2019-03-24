#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;

int main() {
  //take input of numbers
  cin>>n>>m;

  // declare both 2d matrixes as 2d arrays
  ll A[n][m], B[n][m];

  // input both A and B arrays
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>A[i][j];
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>B[i][j];
    }
  }

  // arrange arrays as per i+j sum value
  int maxLimit = m+n-2;
  vector<ll> vA[maxLimit+1];
  vector<ll> vB[maxLimit+1];

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      vA[i+j].push_back(A[i][j]);
      vB[i+j].push_back(B[i][j]);
    }
  }
//   for(int i=0;i<=maxLimit;i++) {
//     cout<<i<<": ";
//     for(int j=0;j<vA[i].size();j++) {
//         cout<<vA[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<endl;

//   for(int i=0;i<=maxLimit;i++) {
//     cout<<i<<": ";
//     for(int j=0;j<vB[i].size();j++) {
//         cout<<vB[i][j]<<" ";
//     }
//     cout<<endl;
//   }

  for(int i=0;i<=maxLimit;i++) {
    sort(vA[i].begin(), vA[i].end());
    sort(vB[i].begin(), vB[i].end());
    if(vA[i]!=vB[i]) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
