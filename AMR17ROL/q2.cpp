#include<bits/stdc++.h>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;

    while(test_cases--) {
        int a,b,c;
        cin>>a>>b>>c;

        int d,e,f;
        cin>>d>>e>>f;

        int l,r;
        cin>>l>>r;

            int p,q,r;
            p=(a+d)/2;
            q=(b+e)/2;
            r=(c+f)/2;

            int ans=abs((a-d)*(pow(r,3)-pow(l,3))*2 + (b-e)*3*(pow(r,2)-pow(l,2)) + (c-f)*6*(r-l));
            int denom=6;

            if(ans%6==0) {
                ans/=6;
                denom=1;
            } else if(ans%3==0) {
                ans/=3;
                denom=2;
            } else if(ans%2==0) {
                ans/=2;
                denom=3;
            }
            printf("%d/%d\n",ans,denom);
    }
    return 0;
}