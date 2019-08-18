#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    int ct=0;
    while(t--) {
        // cout<<"hey"<<endl;
        int n,g,m;
        cin>>n>>g>>m;

        // cout<<n<<" "<<g<<" "<<m<<endl;

        vector<pair<int,int> > icw, iacw;
        vector<int> fposc, fposa;
        map<int,int> endToGuestMapC, endToGuestMapA;
        for(int i=0;i<g;i++) {
            int pos;
            char rdir;

            cin>>pos>>rdir;
            if(rdir=='C') {
                pos=(pos+m)%n;
                if(pos<=0)
                    pos+=n;
                icw.push_back(make_pair(pos,i));
                fposc.push_back(pos);
                endToGuestMapC.insert(make_pair(pos,i));
            } else {
                pos=(pos-m)%n;
                if(pos<=0)
                    pos+=n;
                iacw.push_back(make_pair(pos,i));
                fposa.push_back(pos);
                endToGuestMapA.insert(make_pair(pos,i));
            }
        }

        sort(fposc.begin(), fposc.end());
        sort(fposa.begin(), fposa.end());

        vector<pair<int,set<int> > > timeOfVisit(n);
        map<int,set<int> > guestToPresenceMap;
        
        //proceeding for clockwise first
        for(int i=0;i<n;i++) {
            int num=i+1;
            int ub=upper_bound(fposc.begin(),fposc.end(),num)-fposc.begin();
            if(ub==fposc.size()) {
                ub=upper_bound(fposc.begin(),fposc.end(),num-n)-fposc.begin();
            }
            // cout<<"ub: "<<ub<<endl;
            int fposv=fposc[ub];
            int spos=num;
            if(spos>fposv) {
                spos=num-n;
            }
            int tov=m-(fposv-spos);

            if(!timeOfVisit[i].first) {
            	timeOfVisit[i].first = tov;
            	timeOfVisit[i].second.insert(fposv);
            	continue;
            }

            if(tov>timeOfVisit[i].first) {
                //most recent one to be remembered;
                timeOfVisit[i].first=tov;
                timeOfVisit[i].second.clear();
                timeOfVisit[i].second.insert(fposv);
            } else if(tov=timeOfVisit[i].first) {
                //add to the existing as tov is the same
                timeOfVisit[i].second.insert(fposv);
            }
        }


        cout<<"timeOfVisit after clockwise traversal"<<endl;
        for(int i=0;i<n;i++) {
        	cout<<timeOfVisit[i].first<<" ";
        }
        cout<<endl;


        //proceeding for anticlockwise next
        for(int i=0;i<n;i++) {
            int num=i+1;
            int lb=lower_bound(fposa.begin(),fposa.end(),num)-fposa.begin();
            if(lb==-1) {
                lb=lower_bound(fposa.begin(),fposa.end(),num+n)-fposa.begin();
            }
            int fposv=fposa[lb];
            int spos=num;
            if(spos<fposv) {
                spos=num+n;
            }
            int tov=m-(-fposv+spos);

            if(!timeOfVisit[i].first) {
            	timeOfVisit[i].first = tov;
            	timeOfVisit[i].second.insert(fposv);
            	continue;
            }
            
            if(tov>timeOfVisit[i].first) {
                //most recent one to be remembered;
                timeOfVisit[i].first=tov;
                timeOfVisit[i].second.clear();
                timeOfVisit[i].second.insert(fposv);
            } else if(tov=timeOfVisit[i].first) {
                //add to the existing as tov is the same
                timeOfVisit[i].second.insert(fposv);
            }
        }

        cout<<"timeOfVisit after anti-clockwise traversal"<<endl;
        for(int i=0;i<n;i++) {
        	cout<<timeOfVisit[i].first<<" ";
        }
        cout<<endl;

        int res[g]={0};
        for(int i=0;i<n;i++) {
            set<int>::iterator it;
            for(it=timeOfVisit[i].second.begin(); it!=timeOfVisit[i].second.end(); it++) {
                cout<<"*it: "<<*it<<" ";
                res[endToGuestMapC[*it]]++;
                res[endToGuestMapA[*it]]++;
            }
            cout<<endl;
        }

        //answer display section
        printf("Case #%d: ", ++ct);
        //main loop of results :)
        for(int i=0;i<g;i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

	return 0;
}