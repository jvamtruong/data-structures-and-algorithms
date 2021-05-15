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
int b[10][10];

void bfs() {
	data rec;
	for (int i = 0 ; i < 2; i++) {
		for (int j = 0 ; j < 3; j++) {
			rec.x[i][j] = a[i][j];
		}
	}
	q.push(rec);
	while (!q.empty()) {
		data cur = q.front();
		q.pop();
		bool bl = false;
		for (int i = 0 ; i < 2; i++) {
			for (int j = 0 ; j < 3; j++) {
				if (cur.x[i][j] != b[i][j]) {
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
		for (int i = 0 ; i < 2; i++) {
			for (int j = 0 ; j < 3; j++) {
				l.x[i][j] = cur.x[i][j];
				r.x[i][j] = cur.x[i][j];
			}
		}
		int t = l.x[1][1];
		l.x[1][1] = l.x[0][1];
		l.x[0][1] = l.x[0][0];
		l.x[0][0] = l.x[1][0];
		l.x[1][0] = t;
		t = r.x[1][2];
		r.x[1][2] = r.x[0][2];
		r.x[0][2] = r.x[0][1];
		r.x[0][1] = r.x[1][1];
		r.x[1][1] = t;
		l.cnt = cur.cnt + 1;
		r.cnt = cur.cnt + 1;
		q.push(l);
		q.push(r);
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0 ; i < 6; i++) {
		int x;
		cin >> x;
		if (i < 3) a[0][i] = x;
		else a[1][i % 3] = x;
	}
	for (int i = 0 ; i < 6; i++) {
		int x;
		cin >> x;
		if (i < 3) b[0][i] = x;
		else b[1][i % 3] = x;
	}
	bfs();
}
