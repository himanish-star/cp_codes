class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        
        string codes[16] = {
            "00",
            "11",
            "22",
            "33",
            "44",
            "55",
            "66",
            "77",
            "88",
            "99",
            "aa",
            "bb",
            "cc",
            "dd",
            "ee",
            "ff"
        };
        
        string res1,res2,res3;
        int sc=INT_MAX;
        for(int i=0;i<16;i++) {
            int lsc=pow(stoi(color.substr(1,2),nullptr,16)-stoi(codes[i],nullptr,16),2);
            
            // cout<<lsc<<endl;
            
            if(lsc<sc) {
                sc=lsc;
                res1=codes[i];
            }
        }
        
        sc=INT_MAX;
        for(int i=0;i<16;i++) {
            int lsc=pow(stoi(color.substr(3,2),nullptr,16)-stoi(codes[i],nullptr,16),2);
            
            if(lsc<sc) {
                sc=lsc;
                res2=codes[i];
            }
        }
        
        sc=INT_MAX;
        for(int i=0;i<16;i++) {
            int lsc=pow(stoi(color.substr(5,2),nullptr,16)-stoi(codes[i],nullptr,16),2);
            
            if(lsc<sc) {
                sc=lsc;
                res3=codes[i];
            }
        }
        
        cout<<"#"+res1+res2+res3<<endl;
        
        return "#"+res1+res2+res3;
    }
};