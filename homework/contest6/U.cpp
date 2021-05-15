#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[505][505];
int dx[10] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[10] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m;

void dfs(int u, int v) {
	for (int i = 0 ; i < 8; i++) {
		int x = u + dx[i];
		int y = v + dy[i];
		if (1 <= x && x <= n && 1 <= y && y <= m) {
			if (a[x][y]) {
				a[x][y] = 0;
				dfs(x, y);
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
		int ans = 0;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				if (a[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
	}
}