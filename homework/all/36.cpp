#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 5000;

bool f[MAX + 5][MAX + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		int n = a.length();
		a.insert(0, " ");
		memset(f, false, sizeof f);
		for (int i = 1 ; i <= n; i++) f[i][i] = true;
		for (int k = 1 ; k < n; k++) {
			for (int i = 1 ; i <= n - k; i++) {
				int j = i + k;
				if (a[i] == a[j]) {
					if (j - i == 1) f[i][j] = true;
					else f[i][j] = f[i + 1][j - 1];
				}
			}
		}
		int ans = 1;
		for (int i = 1 ; i < n; i++) {
			for (int j = i + 1 ; j <= n; j++) {
				if (f[i][j]) ans = max(ans, j - i + 1);
			}
		}
		cout << ans << endl;
	}
}