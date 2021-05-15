#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, c, d;
		cin >> n >> c >> d;
		//vector < int > a(n);
		for (int i = 0 ; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n, greater < int > ());
		long long res1 = 0;
		long long res2 = 0;
		int k = min(c, d);
		int t = max(c, d);
		for (int i = 0 ; i < k; i++) {
			res1 += a[i];
		}
		for (int i = k ; i <= k + t - 1; i++) {
			res2 += a[i];
		}
		double ans = ((1.0 * res1) / k) + ((1.0 * res2 ) / t);
		printf("%0.6lf\n", ans);
	}	
}