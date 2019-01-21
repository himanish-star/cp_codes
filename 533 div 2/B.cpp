#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    char prev;
    int count=0,len=0;

    int hist[26]={0},maxAns=0;

    for(int i=0;i<s.length();i++) {
        if(s[i]!=prev) {
            prev=s[i];
            len=0;
        }

        if(s[i]==prev) {
            len++;
            if(len==k) {
                hist[prev-'a']++;
                maxAns=max(maxAns,hist[prev-'a']);
                len=0;
            }
        }
    }

    // for(int i=0;i<26;i++)
    //     cout<<hist[i]<<" ";
    // cout<<endl;
    cout<<maxAns<<endl;

    return 0;
}
