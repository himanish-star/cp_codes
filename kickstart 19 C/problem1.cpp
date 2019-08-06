#include<bits/stdc++.h>

using namespace std;


int main() {
	int test_cases;
	cin>>test_cases;

	int case_count=0;
	while(test_cases--) {
		int n,r,c,sr,sc;
		cin>>n>>r>>c>>sr>>sc;

		sr--,sc--;
		int grid[r][c];
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				grid[i][j]=0;
			}
		}

		grid[sr][sc]=1;

		while(n--) {
			char cmd;
			cin>>cmd;

			switch(cmd) {
				case 'N':
				while(grid[sr][sc]) {
					sr--;
				}
				grid[sr][sc]=1;
				break;
				case 'E':
				while(grid[sr][sc]) {
					sc++;
				}
				grid[sr][sc]=1;
				break;
				case 'W':
				while(grid[sr][sc]) {
					sc--;
				}
				grid[sr][sc]=1;
				break;
				case 'S':
				while(grid[sr][sc]) {
					sr++;
				}
				grid[sr][sc]=1;
				break;
			}
		}
		printf("Case #%d: %d %d\n", ++case_count, sr+1, sc+1);
	}
}