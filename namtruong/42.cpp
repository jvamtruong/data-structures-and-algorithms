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
	for (int i = 1 ; i <= n; i++) {
		bool bl = false;
		for (int j = 1 ; j < n; j++) {
			if (a[j] > a[j + 1]) {
				bl = true;
				break;
			}
		}
		if (bl) {
			int minval = 1E9;
			int idx = i;
			for (int j = i + 1 ; j <= n; j++) {
				if (minval > a[j]) {
					minval = a[j];
					idx = j;
				}
			}
			swap(a[i], a[idx]);
		}
		cout << "Buoc " << i << ": ";
		for (int j = 1 ; j <= n; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		if (!bl) return 0;
	}
}