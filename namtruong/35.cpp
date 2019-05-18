#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;
const int MAX = 1E3;

long long f[MAX + 5][MAX + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0 ; i <= MAX; i++) f[0][i] = 1;
	for (int j = 1 ; j <= MAX; j++) {
		for (int i = 1 ; i <= j; i++) {
			f[i][j] = f[i][j - 1] + f[i - 1][j - 1];
			f[i][j] %= MOD;
		}
	}
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << f[k][n] << endl;
	}	
}