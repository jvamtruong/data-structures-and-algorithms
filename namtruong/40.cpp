#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 5000;

int f[MAX + 5][MAX + 5];
int a[MAX + 5][MAX + 5];

int min(int a, int b, int c) {
	return min(min(a, b), c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0 ; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				f[i][j] = 1E9;
			}
		}
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		f[1][1] = a[1][1];
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				if (i == 1 && j == 1) continue;
				f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + a[i][j];
			}
		}
		cout << f[n][m] << endl;
	}
}