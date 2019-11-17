#include<bits/stdc++.h>

using namespace std;

bool possible;


struct Node {
    int sum;
    bool satisfy;
};

map<string,Node> memo;



void dfs(int arr[],bool add,int sum,int used,int t) {
    int noMoves=0;

    if(possible)
        return;

    for(int i=0;i<9;i++) {
        if(arr[i]>0) {
            arr[i]--;
            
            int vadd;
            
            if(add)
                vadd=i+1;
            else
                vadd=-(i+1);

            dfs(arr,!add,(sum+vadd)%11,used+1,t);
            // if((vadd+res.sum)%11==0)

            arr[i]++;
        } {
            noMoves++;
        }
    }
    if(noMoves==9 && used==t) {
        if(sum%11==0)
            possible=true;
    }
}

int main() {
    int t;
    cin>>t;

    int count=1;
    while(t--) {
        int arr[9];
        int total_digits=0;
        for(int i=0;i<9;i++) {
            cin>>arr[i];
            total_digits+=arr[i];    
        }
        
        possible=false;
        dfs(arr,true,0,0,total_digits);

        cout<<"Case #"<<count++<<": ";
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}