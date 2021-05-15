#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int l[505];
int r[505];
int a[505][505];
int f[505][505];
vector < int > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				f[i][j] = 0;
			}
		}
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j]) f[i][j] = f[i - 1][j] + 1;
			}
		}
		int ans = -1;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				while (!v.empty() && f[i][v.back()] >= f[i][j]) v.pop_back();
				if (v.empty()) l[j] = 1;
				else l[j] = v.back() + 1;
				v.push_back(j);
			}
			v.clear();
			for (int j = m ; j >= 1; j--) {
				while (!v.empty() && f[i][v.back()] >= f[i][j]) v.pop_back();
				if (v.empty()) r[j] = m;
				else r[j] = v.back() - 1;
				v.push_back(j);
			}
			v.clear();
			for (int j = 1 ; j <= m; j++) {
				ans = max(ans, f[i][j] * (r[j] - l[j] + 1));
			}
		}
		cout << ans << endl;
	}
}