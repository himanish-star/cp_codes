#include<bits/stdc++.h>

using namespace std;

long double calculate_expectation(vector<long double> &a, long double n) 
{ 
    long double prb = (1 / n); 
      
    long double sum = 0; 
    for (int i = 0; i < n; i++)  
        sum += a[i] * prb;     
  
    return sum; 
} 

int main() {
    int t,tc=1;
    cin>>t;

    while(t--) {
        int N,A,B; cin>>N>>A>>B;

        unordered_map<int,int> parent;
        for(int i=1;i<=N-1;i++) {
            int x; cin>>x;
            parent[i+1]=x;
        }
        parent[1]=-1;

        vector<set<int>> pathA(N+1), pathB(N+1);
        for(int i=1;i<=N;i++) {
            int node=i, la=0, lb=0;
            while(node>=1) {
                if(la%A==0) pathA[i].insert(node);
                node=parent[node];
                la++;
            }

            node=i;
            while(node>=1) {
                if(lb%B==0) pathB[i].insert(node);
                node=parent[node];
                lb++;
            }
        }

        // for(int i=1;i<=N;i++) {
        //     cout<<"A "<<i<<": ";
        //     for(set<int>::iterator it=pathA[i].begin();it!=pathA[i].end();it++)
        //         cout<<*it<<" ";
        //     cout<<endl;
        // }

        // for(int i=1;i<=N;i++) {
        //     cout<<"B "<<i<<": ";
        //     for(set<int>::iterator it=pathB[i].begin();it!=pathB[i].end();it++)
        //         cout<<*it<<" ";
        //     cout<<endl;
        // }

        vector<long double> temp_res;
        for(int an=1;an<=N;an++) {
            for(int bn=1;bn<=N;bn++) {
                set<int> s1=pathA[an];
                set<int> s2=pathB[bn];
                s1.insert(s2.begin(),s2.end());
                temp_res.push_back(s1.size());
            }
        }
        long double resANs = calculate_expectation(temp_res,temp_res.size());
        // for(int i=0;i<temp_res.size();i++)
        //     cout<<temp_res[i]<<" ";
        // cout<<endl;
        cout<<"Case #"<<tc<<": "<<setprecision(13)<<resANs<<endl; tc++;
    }
    return 0;
}