#include<bits/stdc++.h>
using namespace std;

struct Subset {
    int parent;
    int rank;
};

struct Task {
    int id;
    int deadline;
    int profit;
};

bool cp(Task t1,Task t2) {
    return t1.profit>t2.profit;
}


int find(Subset subsets[],int i) {
    if(subsets[i].parent!=i)
        subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void unionRPC(Subset subsets[],int x,int y) {
    int xset=find(subsets,x);
    int yset=find(subsets,y);
    
    if(subsets[xset].rank>subsets[yset].rank)
        subsets[yset].parent=xset;
    else if(subsets[xset].rank<subsets[yset].rank)
        subsets[xset].parent=yset;
    else {
        subsets[xset].rank++;
        subsets[yset].parent=xset;
    }
}

void sequence(vector<Task> &tasks,int max_deadline) {
    vector<int> slotProfit(max_deadline+1,0);
    
    int tprofit=0,ttask=0;
    
    // Subset *subsets=new Subset[max_deadline];
    // subsets[0]=Subset{0,max_deadline+1};
    // for(int i=1;i<=max_deadline;i++) {
    //     subsets[i]=Subset{i,0};
    // }
    
    for(int i=0;i<tasks.size();i++) {
        int locReq=(tasks[i].deadline);
        
        if(slotProfit[locReq]==0) {
            slotProfit[locReq]=tasks[i].profit;
            tprofit+=tasks[i].profit;
            ttask++;
        } else {
            for(int r=locReq-1;r>=1;r--) {
                if(slotProfit[r]==0) {
                    slotProfit[r]=tasks[i].profit;
                    tprofit+=tasks[i].profit;
                    ttask++;
                    break;
                }
            }
        }
    }
    
    cout<<ttask<<" "<<tprofit<<endl;
}

int main() {
    int test_cases;
    cin>>test_cases;
    
    while(test_cases--) {
        int N;
        cin>>N;
        
        vector<Task> tasks;
        int max_deadline=0;
        for(int i=0;i<N;i++) {
            int id,deadline,profit;
            cin>>id>>deadline>>profit;
            tasks.push_back(Task{id,deadline,profit});
            max_deadline=max(max_deadline,deadline);
        }
        sort(tasks.begin(),tasks.end(),cp);
        sequence(tasks,max_deadline);
    }
	return 0;
}