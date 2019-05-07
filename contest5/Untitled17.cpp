#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct data {
	int x[10][10];
	int cnt;
	data() {
		cnt = 0;
	}
};

queue < data > q;
int a[10][10];
int ans[10][10] = {{1, 2, 3, 0}, {8, 0, 0, 4}, {7, 6, 5, 0}};

void bfs() {
	data cur;
	for (int i = 0 ; i < 3; i++) {
		for (int j = 0 ; j < 4; j++) {
			cur.x[i][j] = a[i][j];
		}
	}
	q.push(cur);
	while (!q.empty()) {
		data cur = q.front();
		q.pop();
		bool bl = false;
		for (int i = 0 ; i < 3; i++) {
			for (int j = 0 ; j < 4; j++) {
				if (cur.x[i][j] != ans[i][j]) {
					bl = true;
					break;
				}
			}
		}
		if (!bl) {
			cout << cur.cnt;
			return;
		}
		data l;
		data r;
		for (int i = 0 ; i < 3; i++) {
			for (int j = 0 ; j < 4; j++) {
				l.x[i][j] = cur.x[i][j];
				r.x[i][j] = cur.x[i][j];
			}
		}
		int t = l.x[1][2];
		l.x[1][2] = l.x[0][1];
		l.x[0][1] = l.x[0][0];
		l.x[0][0] = l.x[1][0];
		l.x[1][0] = l.x[2][0];
		l.x[2][0] = l.x[2][1];
		l.x[2][1] = t;
		t = r.x[1][3];
		r.x[1][3] = r.x[0][2];
		r.x[0][2] = r.x[0][1];
		r.x[0][1] = r.x[1][1];
		r.x[1][1] = r.x[2][1];
		r.x[2][1] = r.x[2][2];
		r.x[2][2] = t;
		l.cnt = cur.cnt + 1;
		r.cnt = cur.cnt + 1;
		q.push(l);
		q.push(r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0 ; i < 3; i++) {
		for (int j = 0 ; j < 3; j++) {
			cin >> a[i][j];
		}
		if (i == 1) cin >> a[i][3];
	}
	bfs();
}
