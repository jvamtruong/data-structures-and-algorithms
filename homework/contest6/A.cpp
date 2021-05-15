#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector < int > a(n);
		for (int i = 0 ; i < n; i++) {
			cin >> a[i];
		}
		int idx = lower_bound(a.begin(), a.end(), k) - a.begin();
		if (a[idx] == k) cout << idx + 1 << endl;
		else cout << "NO" << endl;
	}	
}