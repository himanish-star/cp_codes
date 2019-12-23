class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int np=people.size();
        
        if(!np)
            return 0;
        
        sort(people.begin(),people.end());
        int nb=0,ns=0,ne=np-1;
        
        while(ns<=ne) {
            if(ns==ne) {
                nb++;
                break;
            }
            
            if(people[ne]+people[ns]<=limit) {
                nb++; 
                ne--;
                ns++;
            } else {
                nb++;
                ne--;
            }
                
        }
        
        return nb;
        
    }
};