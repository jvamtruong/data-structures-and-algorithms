#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 500;

int l[MAX + 5];
int r[MAX + 5];
int a[MAX + 5][MAX + 5];
int f[MAX + 5][MAX + 5];
vector < int > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(f, 0, sizeof f);
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j]) f[i][j] = f[i - 1][j] + 1;
			}
		}
		int ans = 0;
		for (int i = 1 ; i <= n; i++) {
			v.clear();
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
			for (int j = 1 ; j <= m; j++) {
				ans = max(ans, min(f[i][j], r[j] - l[j] + 1));
			}
		}
		cout << ans << endl;
	}
}