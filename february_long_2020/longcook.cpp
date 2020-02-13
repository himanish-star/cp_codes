#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define maxyear 1000000

int main() {
    ll tc;
    cin>>tc;

    string day[7]={"Mon","Tue","Wed","Thurs","Fri","Sat","Sun"};
    ll counts[maxyear+1]={0};
    counts[0]=0;
    counts[1]=0;
    ll dc=3;
    
    for(ll i=1,c=1;i<=maxyear;i++,c++) {
        if(dc==5) {
            counts[i]=counts[i-1]+1;
        } else if(dc==6) {
            if(i%400==0 || (i%4==0 && i%100!=0)) {
                counts[i]=counts[i-1];
            } else {
                counts[i]=counts[i-1]+1; 
            }
        } else {
            counts[i]=counts[i-1];
        }
        if(i%400==0 || (i%4==0 && i%100!=0)) {
            // cout<<i<<": year is a leap year"<<endl;
            c=0;
            dc+=2;
        } else {
            dc++;
        }
        dc%=7;
    }
    
    while(tc--) {
        ll m1,t1,m2,t2;
        cin>>m1>>t1;
        cin>>m2>>t2;
        ll c1;

        ll add=0;

        add-=(t1/400)*101;
        add+=(t2/400)*101;

        t1%=400;
        t2%=400;

        if(m2>=2)
            c1=counts[t2];
        else
            c1=counts[t2-1];
            
        ll c2;
        if(m1>2)
            c2=counts[t1];
        else
            c2=counts[t1-1];
        ll val=c1-c2;
        
        // if(t1>t2 || (t1==t2 && m1>m2))
            // val=0;
        
        cout<<val+add<<endl;
    }
    // cout<<counts[2020]<<" "<<counts[2009];
    return 0;
}
