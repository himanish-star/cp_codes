class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        
        if(num==0)
            return num;
        
        int cnum=num;
        while(num) {
            int d=num%10;
            num/=10;
            digits.push_back(d);
        }
        num=cnum;
        
        int is=0,ie=digits.size()-1;
        while(is<ie) {
            if(digits[is]<=digits[ie]) {
                ie--;
            } else {
                vector<int> temp=digits;
                
                int t=digits[is];
                digits[is]=digits[ie];
                digits[ie]=t;
                
                int tnum=0;
                for(int i=0;i<digits.size();i++)
                    tnum+=digits[i]*pow(10,i);
                
                digits=temp;
                num=max(num,tnum);
                is++;
            }
        }
        
        is=0,ie=digits.size()-1;
        while(is<ie) {
            if(digits[is]<=digits[ie]) {
                is++;
            } else {
                vector<int> temp=digits;
                
                int t=digits[is];
                digits[is]=digits[ie];
                digits[ie]=t;
                
                int tnum=0;
                for(int i=0;i<digits.size();i++)
                    tnum+=digits[i]*pow(10,i);
                
                digits=temp;
                num=max(num,tnum);
                is++;
            }
        }
        
        
        int mv=digits[0],mp=0,mnv=digits[0],mnp=0;
        
        for(int i=1;i<digits.size();i++) {
            if(digits[i]>mv) {
                mv=digits[i];
                mp=i;
            } else if(digits[i]<=mnv) {
                mnv=digits[i];
                mnp=i;
            }        
        }
        
        if(mnp>mp) {
            int temp=digits[mnp];
            digits[mnp]=digits[mp];
            digits[mp]=temp;
        }
        
        int ttnum=0;
        for(int i=0;i<digits.size();i++)
            ttnum+=digits[i]*pow(10,i);
        
        
        return max(ttnum,num);
    }
};