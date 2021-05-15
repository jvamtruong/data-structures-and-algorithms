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
		bool bl = false;
		for (int j = i + 1 ; j <= n; j++) {
			if (a[i] > a[j]) {
				bl = true;
				swap(a[i], a[j]);
			}
		}
		if (bl) {
			cout << "Buoc " << i << ": ";
			for (int i = 1 ; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}