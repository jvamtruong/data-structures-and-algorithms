#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E6;

int trace[MAX + 5];
int mark[MAX + 5];
int n;
queue < int > q;
vector < int > ans;

void bfs() {
	q.push(4);
	q.push(7);
	mark[4] = mark[7] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == n) {
			while (true) {
				if (cur == 4 || cur == 7) {
					ans.push_back(cur);
					break;
				}
				ans.push_back(trace[cur]);
				cur -= trace[cur];
			}
			while (!ans.empty()) {
				cout << ans.back();
				ans.pop_back();
			}
			cout << endl;
			return;
		}
		if (cur + 4 > n) continue;
		if (cur + 7 > n) continue; 
		if (!mark[cur + 4]) {
			trace[cur + 4] = 4;
			mark[cur + 4] = true;
			q.push(cur + 4);
		}
		if (!mark[cur + 7]) {
			trace[cur + 7] = 7;
			mark[cur + 7] = true;
			q.push(cur + 7);
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
		cin >> n;
		memset(mark, false, sizeof mark);
		memset(trace, -1, sizeof trace);
		while (!q.empty()) q.pop();
		bfs();
	}	
}