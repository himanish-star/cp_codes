#include<bits/stdc++.h>

using namespace std;

vector<int> gen_prime(int n) {
    vector<int> ps(n+1,1);
    vector<int> prime;

    ps[0]=ps[1]=0;

    for(int i=2;i*i<=n;i++) {
        if(ps[i]==1) {
            for(int j=i*i;j<=n;j+=i) {
                ps[j]=0;
            }
        }
    }

    for(int i=0;i<=n;i++)
        if(ps[i])
            prime.push_back(i);

    return prime;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> prime=gen_prime(n);
        for(int i=0;i<prime.size();i++)
            cout<<prime[i]<<" ";
        cout<<endl;
    }
    return 0;
}
