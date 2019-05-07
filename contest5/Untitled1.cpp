#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[105][105];
int a[105];
int b[105];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m; j++) {
			if (a[i] <= j) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	while (n) {
		if (f[n][m] != f[n - 1][m]) {
			cout << n << endl;
			m -= a[n];
		}
		n--;
	}
}
