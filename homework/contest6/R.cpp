#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > g[1005];
bool mark[1005];

void dfs(int u) {
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
		int n, m;
		cin >> n >> m;
		while (m--) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int q;
		cin >> q;
		while (q--) {
			int x, y;
			cin >> x >> y;
			dfs(x);
			if (!mark[y]) cout << "NO" << endl;
			else cout << "YES" << endl;
			memset(mark, false, sizeof mark);
		}
		for (int i = 1 ; i <= n; i++) g[i].clear();
	}
}