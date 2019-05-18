#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[105][25005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c, n;
	cin >> c >> n;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}		
	for (int j = 1 ; j <= c; j++) {
		for (int i = 1 ; i <= n; i++) {
			if (a[i] <= j) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][c];
}