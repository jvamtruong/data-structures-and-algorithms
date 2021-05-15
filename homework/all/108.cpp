#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

vector < int > graph[MAX + 5];
vector < int > cut;
bool articulation[MAX + 5];
int number[MAX + 5];
int low[MAX + 5];
int order = 0;
int child = 0;
int father[MAX + 5];

void dfs(int u) {
	number[u] = low[u] = ++order;
	for (int i = 0 ; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (!number[v]) {
			father[v] = u;
			if (father[u] == -1) child++;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= number[u]) articulation[u] = true;
		}
		else {
			if (v != father[u]) low[u] = min(low[u], number[v]);
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
		for (int i = 1 ; i <= n; i++) graph[i].clear();
		cut.clear();
		memset(father, 0, sizeof father);
		memset(articulation, false, sizeof articulation);
		memset(number, 0, sizeof number);
		memset(low, 0, sizeof low);
		while (m--) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		order = 0;
		for (int i = 1 ; i <= n; i++) {
			if (!number[i]) {
				father[i] = -1;
				child = 0;
				dfs(i);
				articulation[i] = (child > 1);
			}
		}
		for (int i = 1 ; i <= n; i++) {
			if (articulation[i]) cut.push_back(i);
		}
		cout << cut.size() << endl;
		for (int i = 0 ; i < cut.size(); i++) {
			cout << cut[i] << " ";
		}
		cout << endl;
	}		
}