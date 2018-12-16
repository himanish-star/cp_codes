#include<bits/stdc++.h>

using namespace std;


#define MOD 1000000000
#define ll long long

vector<ll> a,b,c;
ll k;

using namespace std;

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B) {
  vector<vector<ll> > C(k+1, vector<ll>(k+1));

  for(ll i=1;i<=k;i++) {
    for(ll j=1;j<=k;j++) {
      for(ll x=1;x<=k;x++) {
        C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;
      }
    }
  }

  return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p) {
  if(p==1) {
    return A;
  }
  if(p&1) {
    return multiply(A, pow(A,p-1));
  } else {
    vector<vector<ll> > X = pow(A, p/2);
    return multiply(X, X);
  }
}

ll compute(ll n) {
  if(n==0) {
    return 0;
  }

  if(n<=k) {
    return b[n-1];
  }

  vector<ll> F1(k+1);
  for(ll i=1;i<=k;i++) {
    F1[i] = b[i-1];
  }

  vector<vector<ll> > T(k+1, vector<ll>(k+1));

  for(ll i=1;i<=k;i++) {
    for(ll j=1;j<=k;j++) {
      if(i<k) {
        if(j-i==1) {
          T[i][j]=1;
        } else {
          T[i][j]=0;
        }
        continue;
      } else {
        T[i][j] = c[k-j];
        continue;
      }
    }
  }
  T = pow(T, n-1);
  ll res = 0;
  for(int i=1;i<=k;i++) {
    res = (res + (T[1][i]*F1[i]) % MOD) %MOD;
  }
  return res;
}

int main() {
  int C;
  cin>>C;

  while (C--) {
    cin>>k;
    for(ll i=0;i<k;i++) {
      ll temp;
      cin>>temp;
      b.push_back(temp);
    }

    for(ll i=0;i<k;i++) {
      ll temp;
      cin>>temp;
      c.push_back(temp);
    }

    ll n;
    cin>>n;

    cout<<compute(n)<<endl;

    b.clear();
    c.clear();
  }

}
