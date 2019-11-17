#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr,int key)  
{  
    int j=arr.size()-1;
    arr.push_back(0);
    while (j >= 0 && arr[j] > key) 
    {  
        arr[j+1]=arr[j];  
        j = j - 1;  
    }
    arr[j+1]=key;
} 

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

            if(!sorted.size()) {
                sorted.push_back(num);
            } else {
                insertionSort(sorted,num);
            }

            // cout<<"new sorted: ";
            // for(int it=0;it<sorted.size();it++)
            //     cout<<sorted[it]<<" ";
            // cout<<endl;

            if(num>=target) {
                no++;
            }

            if(no>=target) {
                    res.push_back(target);
                    ltarget=target;
                    target++;

                    no=lower_bound(sorted.begin(),sorted.end(),target)-sorted.begin();
                    no=sorted.size()-no;
                    // cout<<"no: "<<no<<", new target: "<<target<<endl;
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