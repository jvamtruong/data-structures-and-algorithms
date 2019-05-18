#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

int f[MAX + 5][MAX + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	a.insert(0, " " );
	b.insert(0, " ");
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= n; j++) {
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}		
	cout << f[n][m];
}