#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E5;

int f[MAX + 5];
int a[15] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000}; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1 ; i <= n; i++) f[i] = 1E9;
		f[0] = 0;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 0 ; j < 10; j++) {
				if (a[j] <= i) f[i] = min(f[i], f[i - a[j]] + 1);
			}
		}
		cout << f[n] << endl;
	}
}