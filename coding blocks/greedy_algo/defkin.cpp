#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
       int w,h,n;
       cin>>w>>h>>n;

       if(n==0) {
           cout<<w*h<<endl;
           continue;
       }

       vector<int> x(n),y(n);

       for(int i=0;i<n;i++) {
           cin>>x[i]>>y[i];
       }

       sort(x.begin(),x.end());
       sort(y.begin(),y.end());

       int maxX=x[0]-1,maxY=y[0]-1;

       for(int i=1;i<n;i++) {
           maxX=max(maxX,x[i]-x[i-1]-1);
           maxY=max(maxY,y[i]-y[i-1]-1);
       }

       maxX=max(maxX,w-x[n-1]);
       maxY=max(maxY,h-y[n-1]);

       cout<<maxX*maxY<<endl;
    }
    return 0;
}
