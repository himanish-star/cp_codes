#include<bits/stdc++.h>

using namespace std;

int countOf1s(int num) {
	int count=0;
	while(num) {
		count+=num&1;
		num>>=1;
	}
	return count;
}

int main() {
	int t;
	cin>>t;

	int cc=0;
	while(t--) {
		int n,q;
		cin>>n>>q;

		string arr[n];
		set<int> s;
		int countOfOdds=0;
		for(int i=0;i<n;i++) {
			int num;
			cin>>num;
			int count = countOf1s(num);
			if(count%2) {
				arr[i]="odd";
				s.insert(i);
				countOfOdds++;
			} else {
				arr[i]="even";
			}
		}

        // for(int i=0;i<n;i++) {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;


		vector<int> result;

		while(q--) {
			int idx,val;
			cin>>idx>>val;

			int ans=0;
			int count = countOf1s(val);
			if(count%2) {
				s.insert(idx);
                if(arr[idx]!="odd")
				    countOfOdds++;
                arr[idx]="odd";
			} else {
				if(arr[idx]=="odd") {
					countOfOdds--;
					s.erase(idx);
				}
                arr[idx]="even";
			}

			int fo,lo;
			if(s.size()) {
				fo=*s.begin();
				lo=*(--s.end());
			}
            // printf("fo %d, lo %d\n",fo,lo);
			if(countOfOdds%2==0) {
				result.push_back(n);
			} else {
				result.push_back(max(n-fo-1,lo));
			}
		}
		printf("Case #%d: ", ++cc);
		for(int i=0;i<result.size();i++) {
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}