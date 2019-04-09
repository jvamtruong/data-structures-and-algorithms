#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E5;

bool mark[MAX + 5];

// https://www.spoj.com/PTIT/problems/ALGOPRO9/
// r - l <= 1E5 (1 <= l <= r < 2 ^ 31)

void init(long long l, long long r) {
	for (long long i = l ; i <= r; i++) {
		mark[i - l] = false;
	}
}

void sieve(long long l, long long r) {
	for (long long i = 2 ; i <= sqrt(r); i++) {
		for (long long j = max(i * i, (l + i - 1) / i * i) ; j <= r; j += i) {
			mark[j - l] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long l, r;
		cin >> l >> r;
		int ans = 0;
		sieve(l, r);
		for (long long i = max(2ll, l) ; i <= r; i++) {
			if (!mark[i - l]) { // i is prime
				ans++;
			}
		}
		cout << ans << endl;
		init(l, r);
	}
}