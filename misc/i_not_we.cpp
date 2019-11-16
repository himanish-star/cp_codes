#include<bits/stdc++.h>

using namespace std;

int uniqueC=0;

void dfs(int idx,vector<int> &v,map<int,int> &m,string str) {
    int adx[3] = {0,1,-1};

    bool noMove=true;
    
    if(idx>=v.size()) {
        // cout<<str<<endl;
        int ssize = str.size(); 
        uniqueC=max(uniqueC,ssize);
        return;
    }

    for(int i=0;i<3;i++) {
        int nn=v[idx]+adx[i];
        if(nn && m[nn]==0) {
            noMove=false;
            m[nn]=1;
            dfs(idx+1,v,m,str+to_string(nn));
            m[nn]=0;
        }
    }

    if(noMove) {
        // cout<<str<<endl;
        int ssize = str.size(); 
        uniqueC=max(uniqueC,ssize);
        return;
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v1(n),v;
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }

    sort(v1.begin(),v1.end());
    v.push_back(v1[0]);
    int last=v1[0],lc=1;

    for(int i=1;i<n;i++) {
        if(v1[i]==last) {
            if(lc<5) {
                v.push_back(v1[i]);
            }
            lc++;
        } else {
            last=v1[i];
            lc=1;
            v.push_back(v1[i]);
        }
    }

    // for(int i=0;i<v.size();i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    map<int,int> m;
    dfs(0,v,m,"");
    cout<<uniqueC;
}