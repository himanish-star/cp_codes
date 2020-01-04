#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
    ll nofi;
    ll nofd;
};

Node query(vector<Node> &st,vector<ll> &arr,int idx,int s,int e,int l,int r) {
    
    if(l>e || r<s) 
        return Node{-1,-1};
    
    if(l<=s && r>=e) {
        // cout<<s<<","<<e<<"-->"<<st[idx].nofi<<"|"<<st[idx].nofd<<endl;
        return st[idx];
    }

    int mid=(s+e)/2,n=arr.size();
    Node lnode = query(st,arr,2*idx,s,mid,l,r);
    Node rnode = query(st,arr,2*idx+1,mid+1,e,l,r);

    if(lnode.nofi!=-1 && lnode.nofd!=-1 && rnode.nofi!=-1 && rnode.nofd!=-1) {
        ll nofi=lnode.nofi+rnode.nofi;
        ll nofd=lnode.nofd+rnode.nofd;
        ll tnofi=nofi,tnofd=nofd;
        
        if(arr[mid+1]>arr[mid] && (mid+1==min(r,e) || arr[mid+1]>arr[mid+2]) && (mid==max(s,l) || arr[mid]<arr[mid-1]))
            nofi++;

        if(arr[mid+1]<arr[mid] && (mid+1==min(r,e) || arr[mid+1]<arr[mid+2]) && (mid==max(s,l) || arr[mid]>arr[mid-1]))
            nofd++;

        if(tnofi==nofi && lnode.nofi && rnode.nofi && arr[mid+1]>arr[mid] && (mid+1==min(r,e) || arr[mid+1]<arr[mid+2]) && (mid==max(s,l) || arr[mid]>arr[mid-1]))
            nofi--;
        
        if(tnofd==nofd && lnode.nofd && rnode.nofd && arr[mid+1]<arr[mid] && (mid+1==min(r,e) || arr[mid+1]>arr[mid+2]) && (mid==max(s,l) || arr[mid]<arr[mid-1]))
            nofd--;

        // cout<<s<<","<<e<<"-->"<<nofi<<"|"<<nofd<<endl;
        return Node{nofi,nofd};
    } else if(lnode.nofi!=-1 && lnode.nofd!=-1) {
        // cout<<s<<","<<e<<"-->"<<lnode.nofi<<"|"<<lnode.nofd<<endl;
        return lnode;
    } else {
        // cout<<s<<","<<e<<"-->"<<rnode.nofi<<"|"<<rnode.nofd<<endl;
        return rnode;
    }
}

void bt(vector<Node> &st,vector<ll> &arr,int idx,int s,int e) {
    if(s==e) {
        st[idx]=Node{0,0};
        // cout<<s<<","<<e<<"-->"<<st[idx].nofi<<"|"<<st[idx].nofd<<endl;
        return;
    }

    int mid=(s+e)/2,n=arr.size();
    bt(st,arr,2*idx,s,mid);
    bt(st,arr,2*idx+1,mid+1,e);

    ll nofi=st[2*idx].nofi+st[2*idx+1].nofi;
    ll nofd=st[2*idx].nofd+st[2*idx+1].nofd;
    ll tnofi=nofi,tnofd=nofd;

    if(arr[mid+1]>arr[mid] && (mid+1==e || arr[mid+1]>arr[mid+2]) && (mid==s || arr[mid]<arr[mid-1]))
        nofi++;

    if(arr[mid+1]<arr[mid] && (mid+1==e || arr[mid+1]<arr[mid+2]) && (mid==s || arr[mid]>arr[mid-1]))
        nofd++;

    if(tnofi==nofi && st[2*idx].nofi && st[2*idx+1].nofi && arr[mid+1]>arr[mid] && (mid+1==e || arr[mid+1]<arr[mid+2]) && (mid==s || arr[mid]>arr[mid-1]))
        nofi--;
    
    if(tnofd==nofd && st[2*idx].nofd && st[2*idx+1].nofd && arr[mid+1]<arr[mid] && (mid+1==e || arr[mid+1]>arr[mid+2]) && (mid==s || arr[mid]<arr[mid-1]))
        nofd--;

    st[idx]=Node{nofi,nofd};
    // cout<<s<<","<<e<<"-->"<<st[idx].nofi<<"|"<<st[idx].nofd<<endl;
}

int main() {
    int n,q;
    cin>>n>>q;

    vector<ll> arr(n);
    for(int i=0;i<n;i++) 
        cin>>arr[i];

    vector<Node> st((4*n)+1,Node{0,0});
    bt(st,arr,1,0,n-1);

    // for(int i=0;i<st.size();i++) {
    //     printf("(%lld,%lld) ",st[i].nofi,st[i].nofd);
    // }
    // cout<<endl;
    while(q--) {
        int l,r;
        cin>>l>>r;

        l--,r--;
        Node ansnode=query(st,arr,1,0,n-1,l,r);
        // cout<<ansnode.nofi<<" xx "<<ansnode.nofd<<endl;
        if(ansnode.nofi==ansnode.nofd)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}