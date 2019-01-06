#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005][6];
int A[2005];
int B[2005];
int f(int n, int m, int k){
	int &ans = dp[n][m][k];
	if(ans != -1)
		return ans;
	ans = 0;
	if(n == 0 || m == 0)
		return ans;
	ans = max(f(n, m - 1, k), f(n - 1, m, k));
	if(A[n] == B[m])
		ans = max(ans, f(n - 1, m - 1, k) + 1);
	if(k)
		ans = max(ans, f(n - 1, m - 1, k - 1) + 1);
	return ans;
}
int main(){
	int i,j,n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	for(i = 1; i <= m; i++)
		scanf("%d", &B[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(n, m, k));
    return 0;
}
