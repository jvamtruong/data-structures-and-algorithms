#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;

long long f[105][1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		memset(f, 0, sizeof f);
		for (int i = 1 ; i <= 9; i++) f[1][i] = 1;
		if (n == 1 && k == 0) {
			cout << 1 << endl;
			continue;
		}
		if (k > 9 * n) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 2 ; i <= n; i++) {
			for (int j = 1 ; j <= k; j++) {
				for (int dig = 0 ; dig <= 9; dig++) {
					if (dig <= j) {
						f[i][j] += f[i - 1][j - dig];
						f[i][j] %= MOD;
					}
				}
			}
		}
		cout << f[n][k] << endl;
	}		
}