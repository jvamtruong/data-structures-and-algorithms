#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;
const int MAX = 15000 * 15000 * 2;

ll x, y, z, l, r;
ll a, b, c;

void solve() {
	ll s = -1; // a + b
	ll p = -1; // a * b
	for (c = 15000 ; c >= 1; c--) { // co dinh c tim a, b
		if (x - c * c > MAX) continue;
		else {
			if (x - c * c <= 0) continue;
			ll res = x - c * c;
			if (res * res - z + c * c * c * c > 0) {
				if (res * res - z + c * c * c * c & 1) continue;
				else res = res * res - z + c * c * c * c >> 1;
				ll _res = sqrt(res);
				if (_res == sqrt(res)) p = _res;
				if (p != -1) {
					if (y - c * c * c > 0) {
						if (x - c * c - p > 0) {
							if ((y - c * c * c) % (x - c * c - p) == 0) {
								s = (y - c * c * c) / (x - c * c - p);
							}
						}
					}
				}
			}
		}
		if (s != -1 && p != -1) {
			ll d = s * s - 4 * p;
			if (d > 0) {
				ll _d = sqrt(d);
				if (_d == sqrt(d)) {
					if ((s + _d & 1) || (s - _d & 1))  continue;
					else {
						if (s + _d > 0 && s - _d > 0) {
							a = s - _d >> 1;
							b = s + _d >> 1;
							if (a > 0 && a < b && b < c) return;
						}
					}
				}
			}
		}
	}
}

ll fpow(ll a, ll b, ll m) {
	ll r = 1; 
	while (b) {
		if (b & 1) r = (r % m) * a % m; 
		a %= m; 
		a = a * a % m; 
		b >>= 1;
	} 
	return r;
}

ll f(ll a, ll n) {
	return (fpow(a, n, MOD) - 1 + MOD) % MOD * fpow(a - 1, MOD - 2, MOD) % MOD; // [((a ^ (n - 1)) - 1) / (a - 1) ] % MOD
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	int t;
 	cin >> t;
 	while (t--) {
 		cin >> x >> y >> z >> l >> r;
 		solve();
 		l++;
 		r++;
 		ll res1;
 		ll res2 = (f(b, r) - f(b, l - 1)) % MOD;
 		ll res3 = (f(c, r) - f(c, l - 1)) % MOD;
 		if (res2 < 0) res2 += MOD;
 		if (res3 < 0) res3 += MOD;
 		if (a == 1) res1 = (r - l + 1) % MOD;
 		else {
 			res1 = (f(a, r) - f(a, l - 1)) % MOD;
 			if (res1 < 0) res1 += MOD;
 		} 
 		cout << (res1 + res2 + res3) % MOD << endl;
 	}
}