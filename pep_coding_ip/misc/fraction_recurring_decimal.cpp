class Solution {
public:
    string fractionToDecimal(int num, int den) {
        long long numerator=num, denominator=den;
        // cout<<numerator*denominator<<endl;
        bool neg=false;
        if((numerator*denominator)<0)
            neg=true;
        
        numerator=abs(numerator);
        denominator=abs(denominator);
        
        long long bpv=numerator/denominator;
        string res=to_string(bpv);
        if(bpv*denominator==numerator) {
            if(neg) res="-"+res;
            return res;
        }
        res+=".";
        
        unordered_map<int,int> fmap, posmap;
        string dec=""; string rep;
        numerator%=denominator;
        int pos=0,rpos;
        while(true) {
            numerator*=10;
            long long val=numerator/denominator;
            dec+=to_string(val);
            if(denominator*val==numerator) {
                res+=dec;
                break;
            } else if(fmap[numerator]) {
                dec.pop_back();
                res+=dec;
                rep=to_string(val);
                rpos=posmap[numerator];
                break;
            }
            fmap[numerator]=1; posmap[numerator]=pos;
            numerator%=denominator;
            pos++;
        }
        
        if(rep.size()) {
            bool inDec=false; int ref;
            for(int i=0;i<res.size();i++) {
                if(res[i]=='.') {
                    inDec=true;
                    ref=i;
                }
                else if(inDec && i-ref-1==rpos) {
                    string temp=res;
                    res=res.substr(0,i)+"(";
                    res+=temp.substr(i,temp.size()-i)+")";
                    break;
                }
            }
        }
        if(neg)
            res="-"+res;
        return res;
    }
};