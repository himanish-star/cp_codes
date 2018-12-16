#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000000


int main() {
  ll n,k;
  cin>>n>>k;

  vector<ll> v;

  for(ll i=0;i<n;i++) {
    ll num;
    cin>>num; //0 is a ladder and 1 is a snake
    v.push_back(num);
  }

  ll dp[n+1];
  dp[1] = 0;

  for(ll i=2;i<=n;i++) {
    dp[i] = 0;
    if(v[i-1]==0) {
      for(ll j=1;j<i;j++) {
        if(i-j<=k && v[j-1]==0) {
          dp[i] += dp[j];
          if(j==1)
            dp[i]++;
        }
      }
    }
  }
  cout<<dp[n];

  return 0;
}
