#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    ll sum = 0, a[n], prefix_sum[n];
    memset(prefix_sum, 0, sizeof(prefix_sum));

    prefix_sum[0] = 1;

    for(int i=0;i<n;i++) {
      cin>>a[i];
      sum += a[i];
      sum %= n;
      sum = (sum+n)%n;
      prefix_sum[sum]++;
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
      ll x = prefix_sum[i];
      ans += (x*(x-1))/2;
    }
    cout<<ans<<endl;
  }
  return 0;
}
