#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//http://vnoi.info/problems/QBMST/
// Time Complexity : O(ElogE)

const int MAX = 15000;

struct Edge {
	int u, v, cost;
};

Edge edge[MAX + 5];
int par[MAX + 5];
int n, m;
int ans = 0;

int root(int x) {
	return par[x] < 0 ? x : (par[x] = root(par[x]));
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
	return u.cost < v.cost;	
}

void kruskal() {
	sort(edge + 1, edge + m + 1, cmp);
	memset(par, -1, sizeof par);
	for (int i = 1 ; i <= m; i++) {
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
	cin >> n >> m;
	for (int i = 1 ; i <= m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].cost;
	}
	kruskal();
	cout << ans;
}