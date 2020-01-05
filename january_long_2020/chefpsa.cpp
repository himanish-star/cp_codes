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

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register ll c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
}

//factorial
int fact=1;
unordered_map<int,int> mp;

int main() {
    
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int t;
    fastscan(t);

    for(int i=1;i<=100000;i++) {
        fact=((ll)fact*i)%mod;
        mp[i]=fact;
    }
    mp[0]=1;

    while(t--) {
        int n;
        fastscan(n);

        vector<int> x(2*n);
        unordered_map<ll,ll> occr;
        ll gsum=0;
        ll allZero=0;
        for(ll i=0;i<2*n;i++) {
            fastscan(x[i]);
            allZero+=(x[i]==0);
            gsum+=x[i];
            occr[x[i]]++;
        }

        ll tsum=gsum/(n+1);
        ll nop=0, ans=1;

        if(allZero==2*n) {
            printf("1\n");
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
                
                ll v1=min((ll)x[i],tsum-x[i]);
                ll v2=max((ll)x[i],tsum-x[i]);
                // unq.insert(make_pair(v1,v2));
                cnts[make_pair(v1,v2)]++;
                continue;
            }
            
        }

        // printf("nop -> %lld\n",nop);
        if(nop!=n+1) {
            printf("0\n");
            continue;
        }
        
        ans=(ans*mp[nop-2])%mod;

        ll divisor=1;
        for(map<pair<ll,ll>,ll>::iterator it=cnts.begin();it!=cnts.end();it++) {
            // ll v1=it->first;
            ll v2=it->second;
            // cout<<"mp"<<mp[cnts[make_pair(v1,v2)]]<<endl;
            divisor=(divisor*mp[v2])%mod;
        }

        ans=modDivide(ans,divisor,mod);
        printf("%lld\n",ans);
    }
    return 0;
}