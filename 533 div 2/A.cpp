#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int elems[n+1],maxE=INT_MIN;
    for(int i=1;i<=n;i++) {
        cin>>elems[i];
        // cout<<elems[i]<<" ";
        maxE=max(maxE,elems[i]);
    }

    // cout<<endl;
    // cout<<maxE<<endl;

    int t,cost=INT_MAX;
    for(int i=1;i<=maxE;i++) {
        int local_cost=0;
        for(int j=1;j<=n;j++) {
            local_cost+=abs(elems[j]-i);
            if(elems[j]!=i)
                local_cost--;
        }
        if(local_cost<cost) {
            t=i;
            cost=local_cost;
        }
    }

    cout<<t<<" "<<cost<<endl;
    return 0;
}
