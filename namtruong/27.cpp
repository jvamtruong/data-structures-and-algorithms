#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;

priority_queue < long long , vector < long long >, greater < long long > > min_heap;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
		min_heap.push(a[i]);
	}
	long long ans = 0;
	while (min_heap.size() >= 2) {
		int a = min_heap.top();
		min_heap.pop();
		int b = min_heap.top();
		min_heap.pop();
		ans += a + b;
		ans %= MOD;
		min_heap.push((a + b) % MOD);
	}
	cout << ans;
}