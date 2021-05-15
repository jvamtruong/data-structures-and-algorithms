#include<bits/stdc++.h>
#define endl '\n'
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i < n; i++) {
		int idx = i;
		int minval = 1E9;
		for (int j = i ; j <= n; j++) {
			if (minval > a[j]) {
				minval = a[j];
				idx = j;
			}
		}
		swap(a[i], a[idx]);
		cout << "Buoc " << i << ":" << " " ;
		for (int k = 1 ; k <= n; k++) {
			cout << a[k] << " " ;
		}
		cout << endl;
	}
}
