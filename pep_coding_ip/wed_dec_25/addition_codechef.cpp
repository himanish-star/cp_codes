#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

char a[MX + 1], b[MX + 1];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		ignore = scanf("%s %s", a, b);
		
		int n = strlen(a);
		int m = strlen(b);
		
		if (b[0] == '0') {
			printf("%d\n", 0);
			continue;
		}
		
		int ans = 1;
		for (int i = n - 1, j = m - 1, k = 0; i >= 0 || j >= 0; i--, j--) {
			int s = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
			if (s == 1) {
				if (k > 0) k++;
			}
			else {
				k = s / 2;
			}
			
			ans = max(ans, k + 1);
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}