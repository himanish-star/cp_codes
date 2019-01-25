#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1005;
char mp[maxn][maxn];
int s[maxn], ans[maxn], vis[maxn][maxn];
int n, m, p, num;
struct pos
{
	int x, y, id;
	pos(int x,int y,int i):x(x),y(y),id(i){}
};
queue<pos> have[10], que;
const int dirx[] = { 1,0,-1,0 };
const int diry[] = { 0,-1,0,1 };
int check(int x,int y)
{
	if (x<1 || x>n || y<1 || y>m)return 0;
	if (mp[x][y] == '#')return 0;
	if (vis[x][y] != 0)return 0;
	return 1;
}
int bfs(int sta)
{
	while (!have[sta].empty())
	{
		que.push(have[sta].front());
		have[sta].pop();
	}
	while (!que.empty())
	{
		//cout << num << endl;
		pos now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int dx = now.x + dirx[i];
			int dy = now.y + diry[i];
			//cout << dx << "   " << dy << endl;
			int nid = now.id;
			//cout << dx << "---" << dy << "---" << nid << endl;
			if (check(dx, dy))
			{
				vis[dx][dy] = now.id;
				num--;
				have[now.id].push(pos(dx, dy, now.id));
			}
		}
	}
	return have[sta].size();
}

int main()
{
	cin >> n >> m >> p;
	num = n * m;
	for (int i = 1; i <= p; i++)
	{
		cin >> s[i];
	}
	memset(mp, 0, sizeof(mp));
	memset(vis, 0, sizeof(mp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == '#')num--;
			if (mp[i][j] >= '1' && mp[i][j] <= '9')
			{
				have[mp[i][j] - '0'].push(pos(i, j, mp[i][j] - '0'));
				vis[i][j] = mp[i][j] - '0';
				num--;
			}
		}
	}
	//cout << num << "!!!" << endl;
	int flag = 0;
	while (num)
	{
		flag = 0;
		for (int i = 1; i <= p; i++)
		{
			for (int j = 1; j <= s[i]; j++)
			{
				if (bfs(i) != 0)
					flag = 1;
				else
					break;
				//cout << num << endl;
			}
		}
		if (flag == 0)break;
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans[vis[i][j]]++;
		}
	}
	for (int i = 1; i <= p; i++)
	{
		cout << ans[i];
		if (i != p)cout << " ";
	}
	/*for (int i = 1; i <= n; i++)
	{
		cout << endl;
		for (int j = 1; j <= m; j++)
		{
			cout << vis[i][j];
		}
	}*/
	return 0;
}
