#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    ll gans=0;
    while(t--) {
        ll n;
        cin>>n;

        vector<vector<ll>> mat(4,vector<ll>(4,0));
        unordered_map<char,ll> um1;
        unordered_map<ll,ll> um2;

        um1['A']=0;
        um1['B']=1;
        um1['C']=2;
        um1['D']=3;

        um2[12]=0;
        um2[3]=1;
        um2[6]=2;
        um2[9]=3;

        for(ll i=0;i<n;i++) {
            char m;
            ll t;
            cin>>m>>t;

            mat[um1[m]][um2[t]]++;
        }

        vector<ll> row_vis(4,0),col_vis(4,0);

        ll col_slot[4]={12,3,6,9};
        char row_slot[4]={'A','B','C','D'};
        ll ans=INT_MIN;
        
        for(ll i=0;i<4;i++) {
            col_vis[i]=1;
            for(ll j=0;j<4;j++) {
                if(col_vis[j])
                    continue;
                col_vis[j]=1;
                for(ll k=0;k<4;k++) {
                    if(col_vis[k])
                        continue;
                    col_vis[k]=1;
                    for(ll l=0;l<4;l++) {
                        if(col_vis[l])
                            continue;
                        col_vis[l]=1;
                        vector<ll> per;
                        per.push_back(mat[0][i]);
                        per.push_back(mat[1][j]);
                        per.push_back(mat[2][k]);
                        per.push_back(mat[3][l]);
                        // printf("%lld,%lld,%lld,%lld,%d\n",mat[0][i],mat[1][j],mat[2][k],mat[3][l],per.size());
                        sort(per.begin(),per.end());

                        ll tcost=25,lans=0;
                        for(int m=0;m<4;m++) {
                            if(per[m]!=0) {
                                lans+=(tcost*per[m]);
                            } else {
                                lans-=100;
                            }
                            tcost+=25;
                        }
                        ans=max(ans,lans);
                        col_vis[l]=0;
                    }
                    col_vis[k]=0;
                }
                col_vis[j]=0;
            }
            col_vis[i]=0;
        }

        cout<<ans<<endl;
        gans+=ans;
    }
    cout<<gans<<endl;
    return 0;
}