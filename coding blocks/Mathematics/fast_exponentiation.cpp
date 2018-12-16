#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fast_expon(ll a, ll b) {
  if(b==1) {
    return a;
  }

  if(b==0) {
    return 1;
  }

  if(b % 2 == 0) {
    return fast_expon(a, b/2) * fast_expon(a, b/2);
  } else {
    return a * fast_expon(a, b-1);
  }
}

int main() {
  ll a,b;
  cin >> a >> b;

  cout << fast_expon(a, b) << endl;

  return 0;
}
