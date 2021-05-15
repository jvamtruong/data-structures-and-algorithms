#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E5;

int par[MAX + 5];

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(par, -1, sizeof par);
		while (m--) {
			int u, v;
			cin >> u >> v;
			merge(u, v);
		}
		int ans = -1E9;
		for (int i = 1 ; i <= n; i++) {
			ans = max(ans, -par[i]);
		}
		cout << ans << endl;
	}	
}