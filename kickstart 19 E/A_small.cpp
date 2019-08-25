#include<bits/stdc++.h>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    int case_count=0;
    while(test_cases--) {
        int n,m;
        cin>>n>>m;

        int ans=0;
        for(int i=0;i<m;i++) {
            int u,v;
            cin>>u>>v;
            if(ans<n-1)
            ans++;
        }
        while(ans<n-1) {
            ans+=2;
        }
        printf("Case #%d: %d\n",++case_count,ans);
    }
    return 0;
}
