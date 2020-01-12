#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPower(ll num) {
    return ceil(log2(num))==floor(log2(num));
}

void fillMtrx1(ll ele1,ll ele2,vector<vector<ll>> &mtrx,vector<pair<ll,ll>> &pairs) {
    mtrx[pairs[0].first][pairs[0].second]=ele1;
    mtrx[pairs[pairs.size()-1].first][pairs[pairs.size()-1].second]=ele1;

    bool turn=true;
    for(ll i=1;i<pairs.size()-1;i+=2) {
        ll ele;
        if(turn) {
            ele=ele2;
        } else {
            ele=ele1;
        }
        mtrx[pairs[i].first][pairs[i].second]=ele;
        mtrx[pairs[i+1].first][pairs[i+1].second]=ele;
        turn=!turn;
    }
}

void fillMtrx2(ll ele1,ll ele2,vector<vector<ll>> &mtrx,vector<pair<ll,ll>> &pairs) {
    bool turn=true;
    for(ll i=0;i<pairs.size();i+=2) {
        ll ele;
        if(turn) {
            ele=ele2;
        } else {
            ele=ele1;
        }
        mtrx[pairs[i].first][pairs[i].second]=ele;
        mtrx[pairs[i+1].first][pairs[i+1].second]=ele;
        turn=!turn;
    }
}

void fillMtrx3(ll ele1,ll ele2,vector<vector<ll>> &mtrx,vector<pair<ll,ll>> &pairs,ll cnt) {
    bool turn=true;
    for(ll i=0;i<pairs.size();i+=cnt) {
        ll ele;
        if(turn) {
            ele=ele2;
        } else {
            ele=ele1;
        }
        
        for(ll j=0;j<cnt;j++)
            mtrx[pairs[i+j].first][pairs[i+j].second]=ele;
        // mtrx[pairs[i+1].first][pairs[i+1].second]=ele;
        turn=!turn;
    }
}

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

        bool gptTurn=true;
        for(ll i=2;i<n;i+=2) {
            if(true) {
                ll x=0,y=i;
                ll count=n;
                vector<pair<ll,ll>> pairs1,pairs2;
                bool change=false;
                while(count--) {
                    if(!change) pairs1.push_back({x,y});
                    if(change) pairs2.push_back({x,y});
                    if(x+1>=n || y+1>=n)
                        change=true;
                    x=(x+1)%n;
                    y=(y+1)%n;
                }

                // cout<<pairs1.size()<<endl;
                if(isPower(i)) {
                    fillMtrx3(ele1,ele2,mtrx,pairs1,i);
                    fillMtrx3(ele2,ele1,mtrx,pairs2,i);
                }
                else if(i%4==0) {
                    ll num=n/2;
                    // if(ceil(sqrt(n)!=floor(sqrt(n))))
                    //     num=sqrt(n*2);
                    // else
                    //     num=sqrt(n);
                    while(i%num!=0) {
                        num/=2;
                    }
                    // if(num<4)
                    //     num=4;
                    fillMtrx3(ele1,ele2,mtrx,pairs1,num);
                    fillMtrx3(ele2,ele1,mtrx,pairs2,num);
                }
                else {
                    if(!gptTurn) {
                        fillMtrx1(ele1,ele2,mtrx,pairs1);
                        fillMtrx1(ele2,ele1,mtrx,pairs2);
                    }
                    else {
                        fillMtrx2(ele2,ele1,mtrx,pairs1);
                        fillMtrx2(ele1,ele2,mtrx,pairs2);
                    }
                }
                
                // if(gptTurn)
                //     fillMtrx1(ele2,ele1,mtrx,pairs2);
                // else
                //     fillMtrx2(ele1,ele2,mtrx,pairs2);

                ele1+=2;
                ele2+=2;
                gptTurn=!gptTurn;
                continue;
            } 
            gptTurn=!gptTurn;
            ll x=0,y=i;
            ll count=n;
            vector<ll> seen(n,0);
            while(count--) {
                if(!seen[x] && !seen[y]) {
                    seen[x]=1;
                    seen[y]=1;
                    mtrx[x][y]=ele1;
                } else {
                    mtrx[x][y]=ele2;
                }
                x=(x+1)%n;
                y=(y+1)%n;
            }
            ele1+=2;
            ele2+=2;
        }

        cout<<"Hooray"<<endl;
        // map<ll,vector<pair<ll,ll>>> coords;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<mtrx[i][j]<<" ";
                // coords[mtrx[i][j]].push_back({i+1,j+1});
            }
            cout<<endl;
        }

        // for(auto it:coords) {
        //     cout<<it.first<<"-->";
        //     map<ll,ll> unqs;
        //     for(auto coord:it.second) {
        //         printf("(%lld,%lld)",coord.first,coord.second);
        //         unqs[coord.first]++;
        //         unqs[coord.second]++;
        //     }

        //     bool allCorrect=true;
        //     for(auto unq:unqs) {
        //         if(unq.second!=1) {
        //             allCorrect=false;
        //         }
        //     }

        //     cout<<" allcorrect --> "<<allCorrect;
        //     cout<<endl;
        // }
    }
    return 0;
}