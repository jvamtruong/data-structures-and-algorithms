#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

int f[MAX + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}	
	a[n + 1] = 1E9;
	f[1] = 1;
	for (int i = 2 ; i <= n + 1; i++) {
		for (int j = 1 ; j < i; j++) {
			if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		} 
	}
	cout << f[n + 1] - 1;
}