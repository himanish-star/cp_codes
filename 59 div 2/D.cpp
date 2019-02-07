#include<bits/stdc++.h>

using namespace std;

string retBinEq(char hex) {
  switch(hex) {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': return "1010";
    case 'B': return "1011";
    case 'C': return "1100";
    case 'D': return "1101";
    case 'E': return "1110";
    case 'F': return "1111";
  }
}

int main() {
  int n;
  cin>>n;

  int sumRow[n][n] = {0};
  int sumCol[n][n] = {0};
  string mat[8];
  for(int i=0;i<n;i++) {
    string line;
    cin>>line;
    int num=1;
    while(num*4<=n) {
      mat[i] += retBinEq(line[num-1]);
      num++;
    }
    // cout<<mat[i]<<endl;
  }

  // calculating sumRow
  for(int i=0;i<n;i++) {
    sumRow[i][0] = mat[i][0] - 48;
    for(int j=1;j<n;j++) {
      sumRow[i][j] = sumRow[i][j-1] + mat[i][j] - 48;
    }
  }

  // calculating sumCol
  for(int i=0;i<n;i++) {
    sumCol[0][i] = mat[0][i] - 48;
    for(int j=1;j<n;j++) {
      sumCol[j][i] = sumCol[j-1][i]+ mat[j][i] - 48;
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<sumRow[i][j]<<" KK ";
    }
    cout<<endl;
  }

  return 0;
}
