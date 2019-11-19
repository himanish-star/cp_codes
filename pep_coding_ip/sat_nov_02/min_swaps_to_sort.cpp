struct Subset {
    int parent;
    int rank;
    int size;
};

int fp(Subset subsets[],int i) {
    if(i!=subsets[i].parent)
        subsets[i].parent = fp(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void unite(Subset subsets[],int x,int y) {
    int xset=fp(subsets,x);
    int yset=fp(subsets,y);
    
    if(subsets[xset].rank>subsets[yset].rank) {
        subsets[yset].parent=xset;
        subsets[xset].size=subsets[xset].size+subsets[yset].size;
    } else if(subsets[xset].rank<subsets[yset].rank) {
        subsets[xset].parent=yset;
        subsets[yset].size=subsets[xset].size+subsets[yset].size;
    } else {
        subsets[xset].rank++;
        subsets[yset].parent=xset;
        subsets[xset].size=subsets[xset].size+subsets[yset].size;
    }
}

int minSwaps(int A[], int N){
    Subset subsets[N];
    
    vector<int> temp;
    for(int i=0;i<N;i++) {
        subsets[i]=Subset{i,0,1};
        temp.push_back(A[i]);
    }
    
    sort(temp.begin(),temp.end());
    map<int,int> valToIdx;
    for(int i=0;i<N;i++)
        valToIdx[temp[i]]=i;
    
    for(int i=0;i<N;i++) {
        int val=A[i];
        int idx=valToIdx[val];
        if(fp(subsets,i)!=fp(subsets,idx)) {
            unite(subsets,i,idx);
        }
    }
    
    set<int> uniqueGrp;
    for(int i=0;i<N;i++) {
        int sg=fp(subsets,i);
        uniqueGrp.insert(sg);
        // cout<<i<<": group->"<<sg<<", size->"<<subsets[sg].size<<endl;
    }
    
    int minSwaps=0;
    set<int>::iterator it;
    for(it=uniqueGrp.begin();it!=uniqueGrp.end();it++)
        minSwaps+=(subsets[*it].size-1);
    return minSwaps;
}
