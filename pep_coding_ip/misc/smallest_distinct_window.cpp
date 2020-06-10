#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;

    while(t--) {
        string s; cin>>s;
        
        set<char> chars;
        for(int i=0;i<s.size();i++) {
            s[i]=tolower(s[i]);
            chars.insert(s[i]);
        }

        int st=0, ed=0;
        int fmap[26]={0};
        // fmap[s[0]-'a']++;

        int minl=s.size(), unqc=chars.size();

        for(;ed<s.size() && unqc>0;ed++) {
            if(fmap[s[ed]-'a']==0) {
                unqc--;
                fmap[s[ed]-'a']++;
            } else {
                fmap[s[ed]-'a']++;
            }
        }
        
        ed--;
        // cout<<st<<" "<<ed<<endl;
        for(;st<=ed && ed<s.size();) {
            minl=min(minl,ed-st+1);
            // cout<<st<<" "<<ed<<endl;
            if(fmap[s[st]-'a']>1) {
                fmap[s[st]-'a']--;
                st++;
            } else {
                ed++;
                if(ed<s.size()) fmap[s[ed]-'a']++;
            }
        }
        cout<<minl<<endl;
    }
	return 0;
}