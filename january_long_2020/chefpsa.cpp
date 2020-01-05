#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

ll modInverse(ll b, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(b, m, &x, &y); 
  
    if (g != 1) 
        return -1; 
  
    return (x%m + m) % m; 
} 
  
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    if (inv == -1) 
       return 0; 
    else
       return (inv * a) % m; 
} 

int main() {
    int t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> x(2*n);
        unordered_map<ll,ll> occr;
        ll gsum=0;
        ll allZero=0;
        for(ll i=0;i<2*n;i++) {
            cin>>x[i];
            allZero+=(x[i]==0);
            gsum+=x[i];
            occr[x[i]]++;
        }

        ll tsum=gsum/(n+1);
        ll nop=0, ans=1;

        if(allZero==2*n) {
            cout<<1<<endl;
            continue;
        }

        map<pair<ll,ll>,ll> cnts;
        bool check=true;
        // set<pair<ll,ll>> unq;
        for(ll i=0;i<x.size();i++) {
            if(occr[x[i]]<=0)
                continue;

            if(tsum==x[i] && check && occr[x[i]]>=2) {
                nop+=2;
                occr[x[i]]-=2;
                // occr[0]-=2;
                check=false;
                continue;
            }

            if(x[i]==tsum-x[i] && occr[x[i]]>=2) {
                occr[x[i]]-=2;
                // unq.insert(make_pair(x[i],x[i]));
                cnts[make_pair(x[i],x[i])]++;
                nop++;
                continue;
            }

            if(x[i]!=tsum-x[i] && occr[tsum-x[i]]>=1) {
                occr[x[i]]--;
                occr[tsum-x[i]]--;
                nop++;
                ans=(ans*2)%mod;
                
                ll v1=min(x[i],tsum-x[i]);
                ll v2=max(x[i],tsum-x[i]);
                // unq.insert(make_pair(v1,v2));
                cnts[make_pair(v1,v2)]++;
                continue;
            }
            
        }

        // printf("nop -> %lld\n",nop);
        if(nop!=n+1) {
            cout<<0<<endl;
            continue;
        }

        //factorial
        ll fact=1;
        unordered_map<ll,ll> mp;
        for(ll i=1;i<=nop-2;i++) {
            fact=(fact*i)%mod;
            mp[i]=fact;
        }
        
        ans=(ans*fact)%mod;

        for(map<pair<ll,ll>,ll>::iterator it=cnts.begin();it!=cnts.end();it++) {
            // ll v1=it->first;
            ll v2=it->second;
            // cout<<"mp"<<mp[cnts[make_pair(v1,v2)]]<<endl;
            ans=modDivide(ans,mp[v2],mod);
            
            if(ans<0)
                ans+=mod;
        }

        cout<<ans<<endl;
    }
    return 0;
}