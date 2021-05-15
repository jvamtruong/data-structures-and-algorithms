#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 500;

int a[MAX + 5][MAX + 5];
int dist[MAX + 5][MAX + 5];
int n, m;
int dx[10] = {0, 0, -1, 1};
int dy[10] = {1, -1, 0, 0};

priority_queue < pair < pair < int, int > , int >, vector < pair < pair < int, int > , int > > , greater < pair < pair < int, int >, int > > > min_heap;

void dijkstra(int x, int y) {
	min_heap.push(make_pair(make_pair(dist[x][y], x), y));
	while (!min_heap.empty()) {
		auto cur = min_heap.top();
		int x = cur.first.second;
		int y = cur.second;
		int min_cost = cur.first.first;
		min_heap.pop();
		//if (min_cost != dist[x][y]) continue;
		for (int i = 0 ; i < 4; i++) {
			int u = x + dx[i];
			int v = y + dy[i];
			if (1 <= u && u <= n && 1 <= v && v <= m) {
				if (dist[u][v] > min_cost + a[u][v]) {
					dist[u][v] = min_cost + a[u][v];
					min_heap.push(make_pair(make_pair(dist[u][v], u), v));
				}
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
		cin >> n >> m;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				dist[i][j] = 1E9;
			}
		}
		dist[1][1] = a[1][1];
		dijkstra(1, 1);
		cout << dist[n][m] << endl;
	}
}