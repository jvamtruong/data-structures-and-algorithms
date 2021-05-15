#include<bits/stdc++.h>
#define endl '\n'
#define III pair < double, pair < int, int > >
using namespace std;

const int MAX = 100;

int par[MAX + 5];
pair < double, double > a[MAX + 5];
vector < III > edge;
double ans = 0;

double dist(pair < double, double > x, pair < double, double > y) {
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
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
	sort(edge.begin(), edge.end());
	for (int i = 0 ; i < edge.size(); i++) {
		int u = root(edge[i].second.first);
		int v = root(edge[i].second.second);
		if (u != v) {
			merge(u, v);
			ans += edge[i].first;
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
		memset(par, -1, sizeof par);
		edge.clear();
		for (int i = 0 ; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		for (int i = 0 ; i < n - 1; i++) {
			for (int j = i + 1 ; j < n; j++) {
				edge.push_back(make_pair(dist(a[i], a[j]), make_pair(i, j)));
			}
		}
		ans = 0;
		kruskal();
		printf("%0.6lf\n", ans);
	}	
}