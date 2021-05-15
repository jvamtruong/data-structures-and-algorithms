#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//--------------------- ???----------------------//
struct data {
	int x, y, cnt;
	data() {
		cnt = 0;
	}
	data(int X, int Y, int Z) {
		x = X;
		y = Y;
		cnt = Z;
	}
};

queue < data > q;
int a, b, c;
int x, y, z, t;
char val[1000][35];
int dx[10] = {0, 0, 1, -1, b, -b};
int dy[10] = {1, -1, 0, 0, 0, 0};
bool mark[1000][35];

void bfs() {
	while (!q.empty()) q.pop();
	q.push(data(x, y, 0));
	mark[x][y] = true;
	while (!q.empty()) {
		data cur = q.front();
		q.pop();
		if (cur.x == z && cur.y == t) {
			cout << cur.cnt << endl;
			return;
		}
		for (int i = 0 ; i < 7; i++) {
			if (cur.x + dx[i] < a * b && cur.y + dy[i] < c && val[cur.x + dx[i]][cur.y + dy[i]] != '#') {
				if (!mark[cur.x + dx[i]][cur.y + dy[i]]) q.push(data(cur.x + dx[i], cur.y + dy[i], cur.cnt + 1));
				mark[cur.x + dx[i]][cur.y + dy[i]] = true;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		memset(mark, false, sizeof mark);
		for (int i = 0 ; i < a * b; i++) {
			for (int j = 0 ; j < c; j++) {
				cin >> val[i][j];
				if (val[i][j] == 'S') {
					x = i;
					y = j;
				}
				if (val[i][j] == 'E') {
					z = i;
					t = j;
				}
			}
		}
		bfs();
	}
}
