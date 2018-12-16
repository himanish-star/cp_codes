#include<bits/stdc++.h>

using namespace std;

int recur(int i,int k,int b[],int c[]) {
  if(i<=k)
    return b[i];
  else {
    int sum=0;
    for(int j=1;j<=k;j++)
      sum+=c[j]+recur(i-j,k,b,c);
    return sum;
  }
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases --) {
    cin >> k;
    int b[k+1], c[k+1];

    for(int i=1;i<=k;i++)
      cin>>b[i];

    for(int i=1;i<=k;i++)
      cin>>c[i];

    int n;
    cin>>n;

    cout<<recur(n,k,b,c)<<endl;
  }
  return 0;
}
