#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string input;
        cin>>input;

        int alpha[26] = {0};
        for(int i=0;i<input.length();i++) {
            alpha[input[i]-'a']++;
        }
        int count=0;
        string res;
        for(int i=0;i<26;i++) {
            if(alpha[i]) {
                count++;
                while(alpha[i]--)
                    res.push_back('a'+i);
            }
        }
        if(count==1)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
