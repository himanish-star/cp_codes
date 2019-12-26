class Solution {
public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        
        while(V--) {
            int idx=K;
            for(int i=K-1;i>=0;i--) {
                if(heights[i]<heights[idx])
                    idx=i;
                if(heights[i]>heights[idx])
                    break;
            }
            
            if(idx==K) {
                for(int i=K+1;i<heights.size();i++) {
                    if(heights[i]<heights[idx])
                        idx=i;
                    if(heights[i]>heights[idx])
                        break;
                }
            }
            
            heights[idx]++;
        }
        
        return heights;
    }
};