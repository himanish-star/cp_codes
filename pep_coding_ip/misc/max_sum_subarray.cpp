// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int maxSumSubarray(int [], int );

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumSubarray(a,n)<<endl;
	}
}

// } Driver Code Ends


/*You are required to complete below method */

int kadane(int A[],int s,int e) {
    int max_sum=A[s], sum=0;
    for(int i=s;i<=e;i++) {
        max_sum=max(max_sum,A[i]);
        if(sum+A[i]>0) {
            sum+=A[i];
        } else {
            sum=A[i];
        }
        max_sum=max(max_sum,sum);
        sum=max(sum,A[i]);
    }
    // cout<<"func: "<<max_sum<<endl;
    return max_sum;
}

int maxSumSubarray(int A[], int n)
{
    int max_sum=kadane(A,0,n-1);
   
    int kdf[n], msf=A[0], sf=0;
    for(int i=0;i<n;i++) {
        msf=max(msf,A[i]);
        if(sf+A[i]>0) {
            sf+=A[i];
        } else {
            sf=A[i];
        }
        msf=max(msf,sf);
        sf=max(sf,A[i]);
        kdf[i]=sf;
    }
    
    int kdb[n], msb=A[n-1], sb=0;
    for(int i=n-1;i>=0;i--) {
        msb=max(msb,A[i]);
        if(sb+A[i]>0) {
            sb+=A[i];
        } else {
            sb=A[i];
        }
        msb=max(msb,sb);
        sb=max(sb,A[i]);
        kdb[i]=sb;
    }
    
    for(int i=1;i<n-1;i++) {
        // cout<<kdf[i-1]<<" "<<kdb[i+1]<<endl;
        max_sum=max(max_sum,kdf[i-1]+kdb[i+1]);
    }
    // cout<<max_sum<<endl;
    return max_sum;
}