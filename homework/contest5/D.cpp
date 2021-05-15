#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E4;

bool mark[MAX + 5];
bool cnt[MAX + 5];
queue < pair < int, int > > q;
vector < int > v;
int a, b;

void bfs() {
	while (!q.empty()) q.pop();
	q.push(make_pair(a, 0));
	cnt[a] = true;
	while(!q.empty()) {
		pair < int, int > val = q.front();
		q.pop();
		if (val.first == b) {
			cout << val.second << endl;
			return;
		}
		int x = val.first;
		v.clear();
		while (x) {
			v.push_back(x % 10);
			x /= 10;
		}
		reverse(v.begin(), v.end());
		for (int i = 0 ; i < 4; i++) {
			for (int j = (i == 0) ? 1 : 0 ; j <= 9; j++) {
				if (j != v[i]) {
					int n = 0;
					for (int k = 0 ; k < v.size(); k++) {
						if (k == i) n = n * 10 + j;
						else n = n * 10 + v[k];
					}
					if (!mark[n]) {
						if (!cnt[n]) {
							q.push(make_pair(n, val.second + 1));
							cnt[n] = true;
						}
					}
				}
			}
		}
	}
}

void sieve() {
	for (int i = 2 ; i <= sqrt(MAX); i++) {
		if (!mark[i]) {
			for (int j = i * i ; j <= MAX; j += i) {
				mark[j] = true;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	sieve();
	while (t--) {
		memset(cnt, false, sizeof cnt);
		cin >> a >> b;
		bfs();
	}
}
