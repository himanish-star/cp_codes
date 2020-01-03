#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        ll n=s.size();
        ll consec=0;
        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1])
                consec++;
        }

        ll t=consec;
        consec=(n*(n+1))/2;
        consec*=t;

        // printf("consec %d\n",consec);

        for(int i=1;i<n;i++) {
            //start from here
            ll c=n-i;
            if(s[i]==s[i-1])
                consec-=c;
            else
                consec+=c;
        }

        for(int i=0;i<n-1;i++) {
            //end over here
            ll c=i+1;
            if(s[i]==s[i+1])
                consec-=c;
            else
                consec+=c;
        }

        cout<<consec<<endl;
    }
    return 0;
}