#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int array[2*n];
  for(int i=0;i<2*n;i++) {
    cin >> array[i];
  }
  sort(array, array + 2*n);
  cout << (array[n] + array[n-1]) / 2 << endl;
  return 0;
}
