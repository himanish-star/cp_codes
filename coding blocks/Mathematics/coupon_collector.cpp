#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;
    double sum = 0.0;
    for(int i=1;i<=n;i++)
      sum += (n)/(i*1.0);
    cout<<fixed<<setprecision(2)<<sum<<endl;
  }
  return 0;
}
