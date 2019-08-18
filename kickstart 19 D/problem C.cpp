#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;

	int ct=0;
	while(t--) {
		ll k,n;
		cin>>k>>n;

		ll spots[n];
		for(int i=0;i<n;i++) {
			cin>>spots[i];
		}

		ll cost[n];
		for(int i=0;i<n;i++) {
			cin>>cost[i];
		}

		ll price=0;
		for(int i=0;i<n;i++) {
			//select warehouse as i
			ll localPrice = cost[i];
			vector<ll> tempPrices;
			//add all other spots as construction
			for(int j=0;j<n;j++) {
				if(j==i) {
					continue;
				} else {
					tempPrices.push_back(cost[j]+abs(spots[i]-spots[j]));
				}
			}


            sort(tempPrices.begin(),tempPrices.end());
			vector<ll>::iterator itr=tempPrices.begin();
			for(int it=0;it<k && itr!=tempPrices.end();it++,itr++) {
				// cout<<*itr<<" $$ ";
                localPrice+=*itr;
			}
            // cout<<"localPrice: "<<localPrice<<endl;
            if(price==0) {
            	price=localPrice;
            } else {
				price=min(price,localPrice);
			}
		}
		printf("Case #%d: %d\n", ++ct, price);
	}
	return 0;
}