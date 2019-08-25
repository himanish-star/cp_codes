#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    int ct=1;
    while(t--) {
        int d,s;
        cin>>d>>s;

        vector<pair<int,int> > slots;
        for(int i=0;i<s;i++) {
            int code,eat;
            cin>>code>>eat;
            slots.push_back(make_pair(code,eat));
        }

        printf("Case #%d: ",ct);
        ct++;
        if(s==1) {
            for(int i=0;i<d;i++) {
                int codeTarget,eatTarget;
                cin>>codeTarget>>eatTarget;

                double r1=codeTarget/(double)(slots[0].first);
                double r2=eatTarget/(double)(slots[0].second);
                if(r1+r2<=1) {
                    cout<<"Y";
                } else {
                    cout<<"N";
                }
            }
            cout<<endl;
        } else if(s==2) {
            for(int i=0;i<d;i++) {
                int codeTarget,eatTarget;
                cin>>codeTarget>>eatTarget;

                double ct_c1=codeTarget/(double)(slots[0].first);
                double et_e1=eatTarget/(double)(slots[0].second);
                double e2_e1=slots[1].second/(double)(slots[0].second);
                double c2_c1=slots[1].first/(double)(slots[0].first);
                
                double r=(1-ct_c1-et_e1+e2_e1)/(double)(e2_e1-c2_c1);

                if(r<=1 && r>=0) {
                    cout<<"Y";
                } else {
                    cout<<"N";
                }

            }
            cout<<endl;
        }
    }
    return 0;
}