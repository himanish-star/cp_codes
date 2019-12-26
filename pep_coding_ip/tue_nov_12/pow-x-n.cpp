class Solution {
public:
    double myPowUtil(double x, int n) {
        cout<<n<<" "<<n%2<<endl;
        
        if(n==1) {
            return x;
        }
        
        if(n==-1) {
            return (double)(1/x);
        }
        
        if(n==0) {
            return 1;
        }
    
        double pow = myPowUtil(x,n/2);
        
        if(n%2==0) {
            return pow * pow;
        } else if(n%2==1) {
            return x * pow * pow;
        } else {
            return pow * double(pow/x);
        }
    }
    
    double myPow(double x, int n) {
        return myPowUtil(x,n);
    }
};