// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 



int findMaxDiff(int [], int n);

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}


// } Driver Code Ends
/*You are required to complete this method */
int findMaxDiff(int A[], int n) {
    vector<int> nslr(n,0);
    vector<int> nsrl(n,0);
    
    stack<int> stk;
    for(int i=0;i<n;i++) {
        while(stk.size() && A[stk.top()]>A[i]) {
            nslr[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
    }
    
    stack<int> stk1;
    for(int i=n-1;i>=0;i--) {
        while(stk1.size() && A[stk1.top()]>A[i]) {
            nsrl[stk1.top()]=i;
            stk1.pop();
        }
        stk1.push(i);
    }
    
    int maxDiff=INT_MIN;
    for(int i=0;i<n;i++) {
        maxDiff=max(maxDiff,abs(A[nslr[i]]-A[nsrl[i]]));
    }
    
    return maxDiff;
}