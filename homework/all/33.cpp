#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool f[205][40005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	f[0][0] = true;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= s; j++) {
			f[i][j] = f[i - 1][j];
			if (a[i] <= j) f[i][j] |= f[i - 1][j - a[i]];
		}
	}
	cout << (f[n][s] ? "YES" : "NO");
}