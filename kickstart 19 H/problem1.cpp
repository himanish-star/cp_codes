#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    int count=1;
    while(t--) {
        int n;
        cin>>n;

        int arr[n];
        int target=1,no=0,ltarget=1;
        vector<int> res;
        vector<int> sorted;
        for(int i=0;i<n;i++) {
            int num;
            cin>>num;
            arr[i]=num;

            if(num>=target) {
                no++;
            }

            if(no>=target) {
                    res.push_back(target);
                    ltarget=target;
                    target++;

                    no=0;
                    for(int j=0;j<=i;j++) {
                        if(arr[j]>=target)
                            no++;
                    }
                } else {
                    res.push_back(ltarget);
                }
        }
        cout<<"Case #"<<count++<<": ";
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}