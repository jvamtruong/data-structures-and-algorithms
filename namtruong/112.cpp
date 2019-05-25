#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 100;

int dist[MAX + 5][MAX + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= n; j++) {
			dist[i][j] = 1E9;
		}
	}		
	for (int i = 1 ; i <= n; i++) dist[i][i] = 0;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		dist[u][v] = c;
		dist[v][u] = c;
	}
	for (int k = 1 ; k <= n; k++) {
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << dist[u][v] << endl;
	}
}