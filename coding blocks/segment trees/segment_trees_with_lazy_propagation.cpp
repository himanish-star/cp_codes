#include<bits/stdc++.h>

using namespace std;

void buildTree(int *tree,int *a,int ss, int se,int index) {
    if(ss==se) {
        tree[index]= a[ss];
        return;
    }
    int mid=(ss+se)/2;
    buildTree(tree,a,ss,mid,2*index);
    buildTree(tree,a,mid+1,se,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int l,int r,int index) {
    if(l<=ss && r>=se) {
        //complete overlap
        return tree[index];
    }

    if(l>se || r<ss) {
        //no overlap
        return INT_MAX;
    }

    //partial overlap
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,l,r,2*index);
    int right=query(tree,mid+1,se,l,r,2*index+1);
    return min(left,right);
}

void update(int *tree,int *a,int ss,int se,int index,int inc,int i) {
    if(index>se || index<ss) {
        return;
    }

    if(ss==se) {
        tree[i]+=inc;
        a[index]+=inc;
        return;
    }
    int mid=(ss+se)/2;
    update(tree,a,ss,mid,index,inc,2*i);
    update(tree,a,mid+1,se,index,inc,2*i+1);
    tree[i]=min(tree[2*i],tree[2*i+1]);
    return;
}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index) {
    if(l>se || r<ss) {
        return;
    }
    if(l<=ss && r>=se) {
        tree[index]+=inc;
        return;
    }
    int mid=(ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

void updateLazy(int *tree,int *lazy,int ss,int se,int l,int r,int inc,int index) {
    if(lazy[index]!=0) {
        tree[index]+=lazy[index];
        if(ss!=se) {
            tree[2*index]+=lazy[index];
            tree[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(l>se || r<ss)
        return;
    if(l<=ss && r>=se) {
        tree[index]+=inc;
        if(ss!=se) {
            lazy[2*index]+=inc;
            lazy[2*index+1]+=inc;
        }
        return;
    }
    int mid=(ss+se)/2;
    updateLazy(tree,lazy,ss,mid,l,r,inc,2*index);
    updateLazy(tree,lazy,mid+1,se,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int queryLazy(int *tree,int *lazy,int ss,int se,int l,int r,int index) {
    if(lazy[index]!=0) {
        tree[index]+=lazy[index];
        if(ss!=se) {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(l>se || r<ss)
        return INT_MAX;
    if(l<=ss && r>=se) {
        return tree[index];
    }
    int mid=(ss+se)/2;
    int left=queryLazy(tree,lazy,ss,mid,l,r,2*index);
    int right=queryLazy(tree,lazy,mid+1,se,l,r,2*index+1);
    return min(left,right);
}

int main() {
    int a[] = {1,3,2,-5,6,4};
    //
    int n=(sizeof(a))/sizeof(int);

    int *tree = new int[4*n+1];
    buildTree(tree,a,0,n-1,1);

    int *lazy = new int[4*n+1];

    // for(int i=0;i<4*n+1;i++)
    //     cout<<tree[i]<<" ";

    int m;
    cin>>m;

    // the number of queries
    while(m--) {
        int t,v1,v2,val;
        cin>>t;
        if(t==1) {
            cin>>v1>>v2;
            cout<<queryLazy(tree,lazy,0,n-1,v1,v2,1)<<endl;
        } else {
            cin>>v1>>v2>>val;
            updateLazy(tree,lazy,0,n-1,v1,v2,val,1);
        }
    }

    return 0;
}
