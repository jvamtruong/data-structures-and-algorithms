#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//http://vnoi.info/problems/QBMST/
// Time Complexity : O((E + V)log(V))

const int MAX = 1E4;

bool mark[MAX + 5];
vector < pair < int, int > > graph[MAX + 5];
priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > min_heap;
int ans = 0;

void prim() {
	min_heap.push(make_pair(0, 1));
	while (!min_heap.empty()) {
		int u = min_heap.top().second;
		int min_cost = min_heap.top().first;
		min_heap.pop();
		if (mark[u]) continue;
		mark[u] = true;
		ans += min_cost;
		for (int i = 0 ; i < graph[u].size(); i++) {
			int v = graph[u][i].second;
			int cost = graph[u][i].first;
			if (!mark[v]) min_heap.push(make_pair(cost, v));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(c, v));
		graph[v].push_back(make_pair(c, u));
	}
	prim();
	cout << ans;
}