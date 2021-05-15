#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 2 * 1E5;

struct Edge {
	int u, v, c;
	Edge(int U, int V, int C) {
		u = U;
		v = V;
		c = C;
	}
};

vector < Edge > edge;
int par[MAX + 5];
long long ans = 0;

int root(int x) {
	while (par[x] > 0) x = par[x];
	return x;
}

void merge(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return;
	if (par[x] < par[y]) {
		par[x] += par[y];
		par[y] = x;
	}
	else {
		par[y] += par[x];
		par[x] = y;
	}
}

bool cmp(Edge u, Edge v) {
	return u.c < v.c;
}

void kruskal() {
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0 ; i < edge.size(); i++) {
		int u = root(edge[i].u);
		int v = root(edge[i].v);
		if (u != v) {
			merge(u, v);
			ans += edge[i].c;
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
		edge.clear();
		memset(par, -1, sizeof par);
		while (m--) {
			int u, v, c;
			cin >> u >> v >> c;
			edge.push_back(Edge(u, v, c));
		}
		ans = 0;
		kruskal();
		cout << ans << endl;
	}
}