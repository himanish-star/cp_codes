#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    int index=0;
    while(t--) {
        int n,p;
        cin>>n>>p;
        vector<int> skills;
        for(int i=0;i<n;i++) {
            int s;
            cin>>s;
            skills.push_back(s);
        }
        sort(skills.begin(),skills.end());
        int sum_array[n];
        sum_array[0]=skills[0];
        for(int i=1;i<n;i++) {
            sum_array[i]=skills[i]+sum_array[i-1];
        }
        int min_val=INT_MAX;
        for(int i=p-1;i<n;i++) {

            int temp;
            if(i==p-1)
              temp=sum_array[i];
            else
              temp=sum_array[i]-sum_array[i-p];
            min_val=min(min_val,(p)*skills[i]-temp);
        }
        cout<<"Case #"<<++index<<": "<<min_val<<endl;
    }
}
