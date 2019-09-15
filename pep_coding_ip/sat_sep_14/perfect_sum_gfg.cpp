#include<bits/stdc++.h>

using namespace std;


int getSubsets(vector<int> &nums, int end, int target,vector<vector<int>> &memo) {
    if(target==0) {
        // printf("\nwow\n");
        return 1;
    }
    
    if(target<0 || end<0) {
        return 0;
    }

    // printf("end: %d, target: %d\n",end,target);
    if(memo[end][target]) {
        return memo[end][target];
    }

    memo[end][target] = getSubsets(nums,end-1,target,memo) + getSubsets(nums,end-1,target-nums[end], memo);
    return memo[end][target];
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            cin>>nums[i];
        }

        int target;
        cin>>target;


        vector<vector<int>> memo;
        for(int i=0;i<n+1;i++) {
            vector<int> row;
            for(int j=0;j<target+1;j++) {
                row.push_back(0);
            }
            memo.push_back(row);
        }

        cout<<getSubsets(nums, n-1, target, memo)<<endl;
    }

    return 0;
}