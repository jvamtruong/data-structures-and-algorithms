#include<bits/stdc++.h>
#define endl '\n'
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
		cout << "Buoc " << i + 1 << ":" << " " ;
		for (int j = 0 ; j < n; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		bool bl = false;
		for (int j = 0 ; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				bl = true;
				break;
			}
		}
		if (!bl) return 0;
	}
}
