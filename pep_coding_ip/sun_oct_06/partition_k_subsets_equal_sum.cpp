class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int numOfSubs = pow(2,n);
        
        int tsum = 0;
        for(int i=0;i<n;i++)
            tsum += nums[i];
        
        if(tsum%k)
            return false;
        
        tsum /= k;
        cout<<"tsum: "<<tsum<<endl;
        
        vector<int> keys;
        unordered_map<int,int> m;
        m[0]=0;
        for(int i=0;i<n;i++) {
            vector<pair<int,int>> tmp;
            for(auto it=m.begin();it!=m.end();it++) {
                if(it->second+nums[i]<=tsum) {
                    int key=it->first;
                    key |= 1<<i;
                    tmp.push_back(make_pair(key,it->second+nums[i]));
                }
            }
            for(auto it:tmp) m[it.first]=it.second;
        }
        
        for(auto it=m.begin();it!=m.end();it++)
            if(it->second==tsum)
                keys.push_back(it->first);
            
        vector<vector<int>> dp(keys.size());
        for(int i=0;i<keys.size();i++) {
            dp[i].push_back(keys[i]);
            for(int j=0;j<i;j++) {
                dp[j].push_back(keys[i]);
                for(int l=0;l<dp[j].size()-1;l++) {
                    if(dp[j][l] & keys[i]) {
                        dp[j].pop_back();
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<keys.size();i++)
            if(dp[i].size() == k)
                return true;
        
        return false;
    }
};