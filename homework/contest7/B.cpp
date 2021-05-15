#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

int cnt[MAX + 5];
bool visit[MAX + 5];
vector < int > graph[MAX + 5];

void dfs(int u) {
	visit[u] = true;
	cnt[u]++;
	for (int i = 0 ; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (!visit[v]) dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	vector < int > a(k + 5);
	for (int i = 0 ; i < k; i++) {
		cin >> a[i];
	}		
	for (int i = 0 ; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	int ans = 0;
	for (int i = 0 ; i < k; i++) {
		memset(visit, false, sizeof visit);
		dfs(a[i]);
	}
	for (int i = 1 ; i <= n; i++) {
		ans += (cnt[i] == k);
	}
	cout << ans;
}