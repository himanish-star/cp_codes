#include<bits/stdc++.h>

using namespace std;

int rec(vector<vector<int>> &stacks, int p, vector<int> &vis) {
    if(p<=0)
        return 0;

    int ans=0;
    for(int i=0;i<stacks.size();i++) {
        if(vis[i])
            continue;
        for(int j=0;j<stacks[i].size();j++) {
            if(p-(j+1)>=0) {
                vis[i]=1;
                ans=max(ans,stacks[i][j]+rec(stacks,p-(j+1),vis));
                vis[i]=0;
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin>>t;

    int id=1;
    while(t--) {
        int n,k,p;
        cin>>n>>k>>p;

        vector<vector<int>> stacks(n,vector<int> (k,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                cin>>stacks[i][j];
            }   
        }

        for(int i=0;i<n;i++) {
            for(int j=1;j<k;j++) {
                stacks[i][j]+=stacks[i][j-1];
            }   
        }

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<k;j++) {
        //         cout<<stacks[i][j]<<" ";
        //     }
        //     cout<<endl;   
        // }

        vector<int> vis(n,0);
        int ans = rec(stacks,p,vis);

        printf("Case #%d: %d\n",id,ans);
        id++;
    }
}