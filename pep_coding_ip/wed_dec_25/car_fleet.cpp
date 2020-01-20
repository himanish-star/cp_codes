class Solution {
    struct Car {
        int p;
        int s;
        float t;
    };
    
public:
    
    static bool compareCarPos(Car a, Car b) {
        return (a.p<b.p);
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        
        if(!n)
            return 0;
        
        vector<Car> cars(n);
        
        for(int i=0;i<n;i++) {
            cars[i]=Car{position[i],speed[i],float(target-position[i])/(float)(speed[i])};
        }
        
        sort(cars.begin(),cars.end(),compareCarPos);
        
        int ans=1;
        float max_time=cars[n-1].t;
        for(int i=n-2;i>=0;i--) {
            // printf("pos = %d, time = %.8f, max_time = %.8f\n",cars[i].p,cars[i].t,max_time);
            if(cars[i].t>max_time) {
                ans++;
                max_time=cars[i].t;
            }
        }
        
        return ans;
    }
};