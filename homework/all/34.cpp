#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[1005][55];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0 ; j < k; j++) {
			f[i][j] = -1E9; 	
		}
	}
	f[1][a[1]] = 1;
	for (int i = 2 ; i <= n; i++) {
		for (int j = 0 ; j < k; j++) {
			f[i][j] = max(f[i - 1][j], f[i - 1][((j - a[i]) % k + k) % k] + 1);
		}
	}
	cout << f[n][0];
}