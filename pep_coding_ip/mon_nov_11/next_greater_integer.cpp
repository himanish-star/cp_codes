class Solution {
public:
    int nextGreaterElement(int n) {
        bool found=false;
        
        vector<int> bits;
        
        while(n) {
            int d=n%10;
            n=n/10;
            bits.push_back(d);
        }
        
        reverse(bits.begin(),bits.end());
        int nb=bits.size();
        int idx=nb-1;
        int p1;
        while(!found && idx>0) {
            if(bits[idx-1]<bits[idx]) {
                p1=idx-1;
                found=true;
                break;
            }
            idx--;
        }
        
        if(!found)
            return -1;
        
        int mv=bits[idx];
        for(int i=idx+1;i<nb;i++) {
            if(bits[i]<bits[idx] && bits[i]>bits[p1]) {
                idx=i;
                mv=bits[i];
            }
        }
        
        int temp=bits[idx];
        bits[idx]=bits[p1];
        bits[p1]=temp;
        
        sort(bits.begin()+p1+1,bits.end());
        
        reverse(bits.begin(),bits.end());
        int num=0;
        for(int i=0;i<bits.size();i++) {
            num+=pow(10,i)*bits[i];
        }
        
        if(num==INT_MIN)
            return -1;
        return num;
    }
};