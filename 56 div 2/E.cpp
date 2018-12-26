#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define add(a,b) ((a)%M + (b)%M)%M
#define minus(a,b) ((a)%M - (b)%M + M)%M
#define prod(a,b) ((a)%M * (b)%M)%M
#define sqr(n) ((n)*(n))

using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

const int M=1e9+7;

void bit_create(OST *bit,int bpos,int apos,int n) {
    int idx=bpos;
    while(idx<=n) {
        bit[idx].insert(mp(apos,bpos));
        idx+=(idx&(-idx));
    }
}

void bit_remove(OST *bit,int bpos,int apos,int n) {
    int idx=bpos;
    while(idx<=n) {
        bit[idx].erase(mp(apos,bpos));
        idx+=(idx&(-idx));
    }
}

int query(OST *bit,int bpos,int apos) {
    int idx=bpos,ans=0;
    while(idx>0) {
        ans+=bit[idx].order_of_key(mp(apos+1,0));
        idx-=(idx&(-idx));
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;

    OST bit[n+1];

    int a[n+1],b[n+1];
    int pos[n+1];
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        b[i]=pos[b[i]];
        bit_create(bit,i,b[i],n);
    }
    while(m--) {
        int t;
        cin>>t;
        if(t==1) {
            int la,ra,lb,rb;
            cin>>la>>ra>>lb>>rb;
            swap(la,lb),swap(ra,rb);
            cout<<query(bit,ra,rb)+query(bit,la-1,lb-1)-query(bit,la-1,rb)-query(bit,ra,lb-1)<<endl;
        } else {
            int lb,rb;
            cin>>lb>>rb;
            bit_remove(bit,lb,b[lb],n);
            bit_remove(bit,rb,b[rb],n);
            bit_create(bit,lb,b[rb],n);
            bit_create(bit,rb,b[lb],n);
            swap(b[lb],b[rb]);

        }
    }
}
