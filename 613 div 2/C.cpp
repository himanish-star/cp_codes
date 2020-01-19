#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 

 ll lcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }  

int main() {
    ll n;
    cin>>n;

    pair<ll,ll> divs={1000000000001,1000000000001};
    for(ll i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            if(lcm(n/i,i)==n && max(n/i,i)<max(divs.first,divs.second)) {
                divs={min(i,n/i),max(i,n/i)};
            }
        }
    }

    cout<<divs.first<<" "<<divs.second<<endl;
}