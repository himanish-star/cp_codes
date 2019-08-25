#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > numberForm(1000000001);

void printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    int oddCount=0,evenCount=0;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) {
                // printf("%d ", i); 
                if(i%2) {
                    oddCount++;
                } else {
                    evenCount++;
                }
            }
  
            else // Otherwise print both 
            {
                if(i%2) {
                    oddCount++;
                } else {
                    evenCount++;
                }

                if((n/i)%2) {
                    oddCount++;
                } else {
                    evenCount++;
                }
            }
        } 
    } 
    numberForm[n].first=oddCount;
    numberForm[n].second=evenCount;
} 

int main() {
    int t;
    cin>>t;

    int ct=1;

    for(int i=1;i<=1000000000;i++) {
        printDivisors(i);
    }

    while(t--) {
        int l,r;
        cin>>l>>r;

        int ans=0;
        for(int num=l;num<=r;num++) {
            if(abs(numberForm[num].first-numberForm[num].second)<=2)
                ans++;
        }
        printf("Case #%d: %d\n",ct,ans);
        ct++;
    }

    //  for(int i=1;i<=1000000;i++) {
    //     printf("%d: (%d,%d)\n",i,numberForm[i].first,numberForm[i].second);
    // }

    return 0;
}