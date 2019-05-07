#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < pair < int, int > > a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0 ; i < n; i++) {
		if (a[i].first >= ans) {
			ans = a[i].first + a[i].second;
		}
		else ans += a[i].second;
	}
	cout << ans;
}