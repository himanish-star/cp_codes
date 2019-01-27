#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin>>n;
  int k;
  cin>>k;

  ll points[n];
  for(int i=0;i<n;i++)
    cin>>points[i];

  string s;
  cin>>s;

  char last = s[0];
  int pos = 0;
  int prevOccurred[n];
  prevOccurred[0]=0;
  for(int i=1;i<n;i++) {
    if(s[i]==last) {
      prevOccurred[i]=pos;
    } else {
      pos=i;
      prevOccurred[i]=i;
    }
    last=s[i];
  }

  // for(int i=0;i<n;i++)
  //   cout<<prevOccurred[i]<<" ";
  // cout<<endl;

  ll ans=0;

  for(int i=n-1;i>=0;i--) {
    if(prevOccurred[i]==i) {
      // printf("normal addition %d -> %d\n", i, points[i]);
      ans+=points[i];
    } else {
      sort(points+prevOccurred[i],points+i+1);
      int cc=0;
      ll localSum=0;
      for(int j=i;j>=prevOccurred[i];j--) {
        localSum+=points[j];
        cc++;
        if(cc>=k)
          break;
      }
      ans+=localSum;
      // printf("addition from %d to %d -> %d\n", prevOccurred[i], i, localSum);
      i-=(i-prevOccurred[i]);
    }
  }

  cout<<ans<<endl;
  // for(int i=0;i<n;i++)
  //   cout<<points[i]<<" ";
  // cout<<endl;
  return 0;
}
