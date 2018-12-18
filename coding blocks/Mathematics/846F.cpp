#include<bits/stdc++.h>

using namespace std;

int last_occurrence[1000005];
long double dp[1000005];

int main() {
  int n;
  cin>>n;

  int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  dp[1] = 1;

  memset(last_occurrence,0,sizeof(last_occurrence));

  long double sum = 1.0;
  last_occurrence[a[0]] = 1;

  for(int i=2;i<=n;i++) {
    dp[i] = dp[i-1] + (i) - last_occurrence[a[i-1]];
    last_occurrence[a[i-1]] = i;
    sum += dp[i];
  }

  cout<<fixed<<setprecision(10)<<(((2*(sum-n))+n)*1.0)/(1LL*n*n)<<endl;

  return 0;
}
