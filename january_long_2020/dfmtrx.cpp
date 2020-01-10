#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        if(n==1) {
            cout<<"Hooray"<<endl;
            cout<<1<<endl;
            continue;
        }

        if(n%2) {
            cout<<"Boo"<<endl;
            continue;
        }

        
        vector<vector<ll>> mtrx(n,vector<ll> (n,0));
        ll xidx=0,yidx=0;
        while(xidx<n && yidx<n) {
            mtrx[xidx++][yidx++]=2*n-1;
        }

        ll ele1=1,ele2=2;
        for(ll i=1;i<n;i+=2) {
            ll x=i,y=0;
            ll count=n;
            bool turn=true;
            while(count--) {
                if(turn) {
                    mtrx[x][y]=ele1;
                } else {
                    mtrx[x][y]=ele2;
                }
                turn=!turn;
                x=(x-1)%n;
                y=(y+1)%n;
                if(x<0)
                    x+=n;
            }   
            ele1+=2;
            ele2+=2;
        }

        for(ll i=2;i<n;i+=2) {
            if(i%4==0) {
                ll x=0,y=i;
                ll count=n;
                bool turn=true;
                ll revele1=ele1,revele2=ele2;
                map<ll,ll> seen;
                while(count--) {
                    if(!seen[x] && !seen[y]) {
                        mtrx[x][y]=ele1;
                        seen[x]=1;
                        seen[y]=1;
                    } else {
                        mtrx[x][y]=ele2;
                    }
                    if(count%2==0)
                        turn=!turn;

                    // if(x+1>=n || y+1>=n && turn) {
                    //     ele1=revele2;
                    //     ele2=revele1;
                    // }

                    x=(x+1)%n;
                    y=(y+1)%n;
                    if(x<0)
                        x+=n;
                }   
                ele1=revele1+2;
                ele2=revele2+2;
                continue;
            }

            ll x=0,y=i;
            ll count=n;
            bool turn=true;
            ll revele1=ele1,revele2=ele2;
            while(count--) {
                if(turn) {
                    mtrx[x][y]=ele1;
                } else {
                    mtrx[x][y]=ele2;
                }
                if(count%2==0)
                    turn=!turn;

                // if(x+1>=n || y+1>=n && turn) {
                //     ele1=revele2;
                //     ele2=revele1;
                // }

                x=(x+1)%n;
                y=(y+1)%n;
                if(x<0)
                    x+=n;
            }   
            ele1=revele1+2;
            ele2=revele2+2;
        }

        cout<<"Hooray"<<endl;
        map<ll,vector<pair<ll,ll>>> coords;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<mtrx[i][j]<<" ";
                coords[mtrx[i][j]].push_back({i+1,j+1});
            }
            cout<<endl;
        }

        for(auto it:coords) {
            cout<<it.first<<"-->";
            map<ll,ll> unqs;
            for(auto coord:it.second) {
                printf("(%lld,%lld)",coord.first,coord.second);
                unqs[coord.first]++;
                unqs[coord.second]++;
            }

            bool allCorrect=true;
            for(auto unq:unqs) {
                if(unq.second!=1) {
                    allCorrect=false;
                }
            }

            cout<<" allcorrect --> "<<allCorrect;
            cout<<endl;
        }
    }
    return 0;
}