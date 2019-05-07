#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > v;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	vector < int > l(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i <= n; i++) {
		while (!v.empty() && a[v.back()] <= a[i]) v.pop_back();
		if (v.empty()) l[i] = 1;
		else l[i] = v.back() + 1;
		v.push_back(i);
	}
	for (int i = 1 ; i <= n; i++) {
		cout << i - l[i] + 1 << " ";
	}
}