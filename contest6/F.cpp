#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < long long, long long > Map;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n);
	vector < int > b(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}	
	for (int i = 0 ; i < n; i++) {
		cin >> b[i];
		Map[b[i]]++;
	}
	for (int i = 0 ; i < n; i++) {
		int res = INT_MAX;
		for (int j = 0 ; j < n; j++) {
			if (b[j] >= a[i] && res > b[j]) {
				if (Map[b[j]]) {
					res = b[j];
				}
			}
		}
		Map[res]--;
	}
	for (int i = 0 ; i < n; i++) {
		if (Map[b[i]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}