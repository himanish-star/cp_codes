#include<bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin>>s;

  int hor=0,ver=0;
  for(int i=0;i<s.length();i++) {
    if(s[i]=='0') {
      if(ver) {
        printf("1 1\n");
        ver=0;
      } else {
        printf("3 1\n");
        ver=1;
      }
    } else {
      if(hor) {
        printf("1 1\n");
        hor=0;
      } else {
        printf("1 3\n");
        hor=1;
      }
    }
  }
  return 0;
}
