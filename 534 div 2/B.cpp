#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin>>s;
  int turn=0;

  stack<char> st;
  st.push(s[0]);
  for(int i=1;i<s.length();i++) {
    if(!st.size()) {
      st.push(s[i]);
      continue;
    }
    if(st.top()==s[i]) {
      turn++;
      st.pop();
      continue;
    }
    st.push(s[i]);
  }
  if(turn%2) {
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}
