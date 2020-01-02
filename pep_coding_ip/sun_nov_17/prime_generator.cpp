#include<bits/stdc++.h>

using namespace std;

#define mLim 1000000000

vector<int> getPrime(int N) {
    vector<int> ps(N+1,1);
    
    ps[0]=ps[1]=0;
    for(int i=2;i*i<=N;i++) {
        if(ps[i]==1) {
            for(int j=i*i;j<=N;j+=i)
                ps[j]=0;
        }
    }

    vector<int> primes;

    for(int i=0;i<=N;i++) {
        if(ps[i]==1)
            primes.push_back(i);
    }

    return primes;
}

int main() {
    int t;
    cin>>t;

    vector<int> primes = getPrime(sqrt(mLim)+1);
    
    // for(int i=0;i<primes.size();i++) {
    //     cout<<primes[i]<<" ";
    // }
    // cout<<endl;

    while(t--) {
        int l,r;
        cin>>l>>r;

        vector<int> pres(r-l+1,1);

        for(int i=0;i<primes.size();i++) {
            int pn=primes[i];

            // cout<<pn<<"pn in consideration"<<endl;
            int low=floor(l/pn)*pn;

            if(low<l)
                low+=pn;

            for(int j=low;j<=r;j+=pn)
                if(j!=pn)
                    pres[j-l]=0;
        }

        for(int i=l;i<=r;i++) {
            if(pres[i-l] && i!=1)
                cout<<i<<endl;
        }

        cout<<endl;
    }

    return 0;
}