#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin>>n;

    ll mat[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        double fraction=(mat[i][(i+1)%n])/(double)mat[(i+2)%n][(i+1)%n];
        mat[i][i]=ceil(fraction * mat[(i+2)%n][i]);
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++) {
        cout<<(ll)pow(mat[i][i],0.5)<<" ";
    }

    return 0;
}