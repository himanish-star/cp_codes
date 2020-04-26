#include<bits/stdc++.h>

using namespace std;

int check(int a,int b,int c,int d,int e) {
    vector<int> slots(5,0);
    while(a<5 && slots[a]!=0)
        a++;
    if(a<5) {
        slots[a]=1;
    } else {
        return 0;
    }

    while(b<5 && slots[b]!=0)
        b++;
    if(b<5) {
        slots[b]=1;
    } else {
        return 0;
    }
    
    while(c<5 && slots[c]!=0)
        c++;
    if(c<5) {
        slots[c]=1;
    } else {
        return 0;
    }

    while(d<5 && slots[d]!=0)
        d++;
    if(d<5) {
        slots[d]=1;
    } else {
        return 0;
    }

    while(e<5 && slots[e]!=0)
        e++;
    if(e<5) {
        slots[e]=1;
    } else {
        return 0;
    }

    // printf("a%d b%d c%d d%d e%d\n",a+1,b+1,c+1,d+1,e+1);
    return 1;
}

int main() {
    vector<int> slots(5,0);

    int ans=0;
    for(int a=0;a<5;a++) {
        for(int b=0;b<5;b++) {
            for(int c=0;c<5;c++) {
                for(int d=0;d<5;d++) {
                    for(int e=0;e<5;e++) {
                        ans += check(a,b,c,d,e);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}