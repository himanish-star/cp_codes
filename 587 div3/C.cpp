#include<bits/stdc++.h>

using namespace std;

int main() {
    int ml=INT_MAX,mr=INT_MIN,mt=INT_MIN,mb=INT_MAX;

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;


    for(int i=0;i<2;i++) {
       int x3,y3,x4,y4;
       cin>>x3>>y3>>x4>>y4;
        
        ml=min(ml,x3);
        mr=max(mr,x4);

        mb=min(mb,y3);
        mt=max(mt,y4);
    }

    printf("ml %d, mr %d, mb %d, mt %d\n",ml,mr,mb,mt);

    if(x1>=ml && x2<=mr && y1>=mb && y2<=mt) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }

    return 0;
}