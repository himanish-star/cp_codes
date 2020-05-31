#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin>>N;

    vector<int> ele(N);
    int rsize = ceil(sqrt(N));
    
    for(int i=0;i<N;i++)
        cin>>ele[i];
    
    vector<int> rmqArray;
    for(int i=0;i<N;i+=rsize) {
        int v=INT_MAX;
        for(int j=0;i+j<N && j<rsize;j++) {
            v=min(v,ele[i+j]);
        }
        rmqArray.push_back(v);
    }

    

    int Q;
    cin>>Q;

    while(Q--) {
        int l,r; cin>>l>>r;
        int min_val=min(ele[l],ele[r]);
        
        while(l%rsize!=0 &&  l<r) {
            min_val = min(min_val, ele[l]);
            l++;
        }

        while(r%rsize!=0 &&  l<r) {
            min_val = min(min_val, ele[r]);
            r--;
        }

        if(l%rsize==0 && r%rsize==0) {
            int sidx=l/rsize, eidx=r/rsize;
            for(int i=sidx;i<eidx;i++) {
                min_val=min(min_val,rmqArray[i]);
            }
        }

        cout<<min_val<<endl;    
    }

    // for(int i=0;i<rmqArray.size();i++) {
    //     cout<<rmqArray[i]<<" ";
    // }
    // cout<<endl;
}