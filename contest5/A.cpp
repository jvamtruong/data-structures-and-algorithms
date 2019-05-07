#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < int > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			if (x == 1) cout << q.size() << endl;
			if (x == 2) {
				if (q.empty()) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			if (x == 3) {
				int val;
				cin >> val;
				q.push(val);
			}
			if (x == 4) {
				if (!q.empty()) q.pop();
			}
			if (x == 5) {
				if (!q.empty()) cout << q.front() << endl;
				else cout << -1 << endl;
			}
			if (x == 6) {
				if (!q.empty()) cout << q.back() << endl;
				else cout << -1 << endl;
			}
		}
		while (!q.empty()) q.pop();
	}
}
