#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

vector < int > graph[MAX + 5];
queue < int > q;
bool visit[MAX + 5];
int trace[MAX + 5];

void bfs(int u) {
	q.push(u);
	visit[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0 ; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (!visit[v]) {
				trace[v] = u;
				visit[v] = true;
				q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m >> u >> v;
		for (int i = 1 ; i <= n; i++) graph[i].clear();
		memset(trace, -1, sizeof trace);
		memset(visit, false, sizeof visit);
		while (m--) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bfs(u);
		if (visit[v]) {
			int cnt = 0;
			while (trace[v] != -1) {
				v = trace[v];
				cnt++;
			}
			cout << cnt << endl;
		}
		else cout << -1 << endl;
	}
}