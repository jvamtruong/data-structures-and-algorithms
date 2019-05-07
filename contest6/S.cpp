#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > g[1005];
bool mark[1005];
int cnt = 0;

void dfs(int u) {
	cnt++;
	mark[u] = true;
	for (int i = 0 ; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!mark[v]) {
			mark[v] = true;
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(mark, false, sizeof mark);
		cnt = 0;
		for (int i = 1 ; i <= n; i++) g[i].clear();
		for (int i = 0 ; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1);
		if (cnt == n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}