#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[505][505];
bool mark[505][505];
queue < pair < int, int > > q;
queue < pair < int, int > > cur;
int n, m;
int ans = 0;
int dx[10] = {0, 1, -1, 0};
int dy[10] = {1, 0, 0, -1};

void solve() {
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m; j++) {
			if (a[i][j] == 2) {
				q.push(make_pair(i, j));
				mark[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		while (!q.empty()) {
			pair < int, int > x = q.front();
			q.pop();
			for (int i = 0 ; i < 4; i++) {
				if (x.first + dx[i] >= 1 && x.first + dx[i] <= n && x.second + dy[i] >= 1 && x.second + dy[i] <= m) {
					if (a[x.first + dx[i]][x.second + dy[i]] == 1 && !mark[x.first + dx[i]][x.second + dy[i]]) {
						cur.push(make_pair(x.first + dx[i], x.second + dy[i]));
						a[x.first + dx[i]][x.second + dy[i]] = 2;
						mark[x.first + dx[i]][x.second + dy[i]] = true;
					}
				}
			}
		}
		if (!cur.empty()) ans++;
		while (!cur.empty()) {
			q.push(cur.front());
			cur.pop();
		}
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m; j++) {
			if (a[i][j] == 1) {
				cout << -1;
				return;
			}
		}
	}
	cout << ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m; j++) {
			cin >> a[i][j];
		}
	}	
	solve();
}