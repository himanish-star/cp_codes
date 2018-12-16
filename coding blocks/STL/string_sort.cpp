#include<bits/stdc++.h>
#include<string>

using namespace std;

bool cp(string a, string b) {
  if(a.find(b) != string::npos) {
    return true;
  }
  else if(b.find(a) != string::npos)
    return false;
  return a < b;
}

int main() {
  int N;
  string flush;
  cin >> N;

  string array[N];
  for(int i=0; i<N; i++) {
    cin >> array[i];
  }
  sort(array, array + N, cp);

  for(int i=0; i<N; i++) {
    cout << array[i] << endl;
  }

  return 0;
}
