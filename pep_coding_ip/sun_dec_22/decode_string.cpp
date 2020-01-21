class Solution {
public:
    
    string travelBack(string S, int K, int e, long long int &lidx) {
        while(e>=0 && !(S[e]>='2' && S[e]<='9')) {
            if(lidx==K)
                return S.substr(e,1);
            lidx--;
            e--;
        }
        
        if(S[e]>='2' && S[e]<='9') {
            int cnt=S[e]-'0';
            while(cnt--) {
                string res = travelBack(S, K, e-1, lidx);
                if(res!="not found")
                    return res;
            }
        }
        
        return "not found";
    }
    
    string decodeAtIndex(string S, int K) {
        long long int lidx=0;
        for(int i=0;i<S.size();i++) {
            if(S[i]>='2' && S[i]<='9') {
                lidx*=S[i]-'0';
            } else {
                lidx++;
            }
        }
        
        cout<<lidx<<endl;
        
        for(int i=S.size()-1;i>=0;i--) {
            if(S[i]>='2' && S[i]<='9') {
                lidx/=(int)(S[i]-'0');
            } else {
                K%=lidx;
                if(K==0) {
                    return S.substr(i,1);
                } else {
                    lidx--;
                }
            }
        }
        
        return "o";
    }
};