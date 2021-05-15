#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 15000;

struct Edge {
	int u, v, cost;
	Edge(int U, int V, int C) {
		u = U;
		v = v;
		cost = C;
	}
};

vector < Edge > edge;
int par[MAX + 5];
int ans = 0;

bool cmp(Edge u, Edge v) {
	return u.cost < v.cost;
}

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

void kruskal() {
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0 ; i < edge.size(); i++) {
		int u = root(edge[i].u);
		int v = root(edge[i].v);
		if (u != v) {
			merge(u, v);
			ans += edge[i].cost;
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
		edge.push_back(Edge(u, v, c));
	}	
	memset(par, -1, sizeof par);
	kruskal();
	cout << ans;
}