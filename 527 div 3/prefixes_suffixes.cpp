#include<bits/stdc++.h>

using namespace std;

bool matcher(string a, string b) {
    int len = min(a.length(),b.length());

    for(int i=0;i<len;i++) {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

bool cp(pair<string,int> a, pair<string,int> b) {
    return a.first.length() < b.first.length();
}

bool rev_matcher(string a, string b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int len = min(a.length(),b.length());

    for(int i=0;i<len;i++) {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    if(n==1) {
        cout<<"P";
        return 0;
    }

    if(n==2) {
        cout<<"PS";
        return 0;
    }

    vector<pair<string,int> > subs;
    vector<string> temp1, temp2;

    char ans[2*n-2];

    for(int i=0;i<2*n-2;i++) {
        string s;
        cin>>s;
        subs.push_back(make_pair(s,i));

        if(s.length()==n-1) {
            temp2.push_back(s);
        } else if(s.length()==1) {
            temp1.push_back(s);
        }
    }

    sort(subs.begin(),subs.end(),cp);

    int count = 0;
    for(int i=0;i<2*n-2;i++) {
        if(matcher(subs[i].first,temp2[0])) {
            count++;
            if(i%2==0)
                i++;
        }
    }

    string res;

    if(count==n-1) {
        res=temp2[0];
    } else {
        res=temp2[1];
    }


    for(int i=0;i<2*n-2;i+=2) {
        if(matcher(subs[i].first,res)) {
            ans[subs[i].second]='P';
            ans[subs[i+1].second]='S';
        }
        else {
            ans[subs[i].second]='S';
            ans[subs[i+1].second]='P';
        }
    }

    res = "";
    for(int i=0;i<2*n-2;i++) {
        res += ans[i];
    }

    cout<<res;
    return 0;
}
