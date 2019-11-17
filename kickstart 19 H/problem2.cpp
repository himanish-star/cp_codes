#include<bits/stdc++.h>

using namespace std;

bool possible;


map<string,vector<int>> memo;

vector<int> dfs(int arr[],bool add,int sum,int used,int t) {
    string id="";

    for(int i=0;i<9;i++) {
        id+=to_string(arr[i]);
        id+="-";
    }

    if(memo.find(id)!=memo.end()) {
        return memo[id];
    }

    vector<int> sums;
    for(int i=0;i<9;i++) {
        if(arr[i]>0) {
            arr[i]--;
            
            int vadd;
            
            if(add)
                vadd=i+1;
            else
                vadd=-(i+1);

            vector<int> res_sums=dfs(arr,!add,(sum+vadd)%11,used+1,t);
            for(int j=0;j<res_sums.size();j++) {
                sums.push_back((vadd+res_sums[j])%11);
            }

            arr[i]++;
        }
    }
    if(sums.size())
        return memo[id]=sums;
    else {
        sums.push_back(0);
        return memo[id]=sums;
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
        vector<int> res_sums=dfs(arr,true,0,0,total_digits);

        for(int i=0;i<res_sums.size();i++) {
            if(res_sums[i]%11==0) {
                possible=true;
                break;
            }
        }

        cout<<"Case #"<<count++<<": ";
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}