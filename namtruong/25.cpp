#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool cmp(pair < int, int > u, pair < int, int > v) {
	return u.second < v.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < pair < int, int > > a(n);
		for (int i = 0 ; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end(), cmp);
		int ans = 1;
		int f = a[0].second;
		for (int i = 1 ; i < n; i++) {
			if (a[i].first >= f) {
				f = a[i].second;
				ans++;
			}
		}
		cout << ans << endl;
	}	
}