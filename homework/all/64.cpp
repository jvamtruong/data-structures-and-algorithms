#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E5;

int r[MAX + 5];
vector < int > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < int > a(n + 5);
		for (int i = 1 ; i <= n; i++) {
			cin >> a[i];
		}
		a[n + 1] = -1;
		v.clear();
		for (int i = n ; i >= 1; i--) {
			while (!v.empty() && a[v.back()] <= a[i]) v.pop_back();
			if (v.empty()) r[i] = n;
			else r[i] = v.back() - 1;
			v.push_back(i);
		}
		for (int i = 1 ; i <= n; i++) {
			cout << a[r[i] + 1] << " ";
		}
		cout << endl;
	}			
}