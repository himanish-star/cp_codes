#include<bits/stdc++.h>

using namespace std;

int compute(int matrix[250][250],vector<pair<int,int> > offices,int r,int c) {
    int time=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(matrix[i][j]) {
                time=max(time,0);
            } else {
                int ltime=INT_MAX;
                for(int k=0;k<offices.size();k++) {
                    ltime=min(ltime,abs(i-offices[k].first) + abs(j-offices[k].second));
                }
                time=max(ltime,time);
            }
        }
    }
    // printf("time: %d, ",time);
    return time;
}

int main() {
    int t;
    cin>>t;

    int cc=0;
    while(t--) {
        int r,c;
        cin>>r>>c;

        // printf("\nRow: %d, Column: %d\n", r,c);

        int matrix[250][250];
        vector<pair<int,int> > offices;        
        for(int i=0;i<r;i++) {
            string str;
            cin>>str;
            for(int j=0;j<c;j++) {
                matrix[i][j]=str[j]-'0';
                if(matrix[i][j]) {
                    offices.push_back(make_pair(i,j));
                }
            }
        }

        //place new delivery office
        int answer=INT_MAX;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                // cout<<matrix[i][j]<<" ";
                if(!matrix[i][j]) {
                    matrix[i][j]=1;
                    offices.push_back(make_pair(i,j));
                    
                    answer=min(answer,compute(matrix,offices,r,c));
                    
                    matrix[i][j]=0;
                    offices.pop_back();
                } else {
                    answer=min(answer,compute(matrix,offices,r,c));
                }
            }
            // cout<<endl;
        }

        printf("Case #%d: %d\n",++cc,answer);
    }
    return 0;
}