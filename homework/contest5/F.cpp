#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

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
char x[105][105];
bool mark[105][105];
int n;
int a, b, c, d;

void bfs() {
	q.push(data(a, b, 0));
	mark[a][b] = true;
	while (!q.empty()) {
		data cur = q.front();
		q.pop();
		if (cur.x == c && cur.y == d) {
			cout << cur.cnt;
			return;
		}
		for (int i = 1 ; i < n - cur.y; i++) {
			if (x[cur.x][cur.y + i] == 'X') break;
			else {
				if (!mark[cur.x][cur.y + i]) q.push(data(cur.x, cur.y + i, cur.cnt + 1));
				mark[cur.x][cur.y + i] = true;
			}
		}
		for (int i = 1 ; i <= cur.y; i++) {
			if (x[cur.x][cur.y - i] == 'X') break;
			else {
				if (!mark[cur.x][cur.y - i]) q.push(data(cur.x, cur.y - i, cur.cnt + 1));
				mark[cur.x][cur.y - i] = true;
			}
		}
		for (int i = 1 ; i < n - cur.x; i++) {
			if (x[cur.x + i][cur.y] == 'X') break;
			else {
				if (!mark[cur.x + i][cur.y]) q.push(data(cur.x + i, cur.y, cur.cnt + 1));
				mark[cur.x + i][cur.y] = true;
			}
		}
		for (int i = 1 ; i <= cur.x; i++) {
			if (x[cur.x - i][cur.y] == 'X') break;
			else {
				if (!mark[cur.x - i][cur.y]) q.push(data(cur.x - i, cur.y, cur.cnt + 1));
				mark[cur.x - i][cur.y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < n; j++) {
			cin >> x[i][j];
		}
	}
	cin >> a >> b >> c >> d;
	bfs();
}
