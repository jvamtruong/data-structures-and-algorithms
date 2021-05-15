#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
inline ll max(ll a, ll b) {return a < b ? b : a;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b;a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a * (b / gcd(a, b));}

ll fpow(ll a, ll b, ll m) {
	ll r = 1; 
	while (b) {if (b & 1) r = (r % m) * a % m; 
		a %= m; 
		a = a * a % m; 
		b >>= 1;
	} 
	return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	int t;
 	cin >> t;
 	vector < ll > a;
 	a.push_back(-1);
 	for (int i = 1 ; i <= 50; i++) {
 		a.push_back(fpow(2, i, LONG_LONG_MAX));
 	}
 	while (t--) {
 		ll n, l, r;
 		cin >> n >> l >> r;
 		vector < ll > b;
 		b.clear();
 		if (n == 1) {
 			if (l > 1) {
 				cout << 0 << endl;
 				continue;
 			}
 			if (l == 1) {
 				cout << 1 << endl;
 				continue;
 			}
 		}
 		ll sz = log(n) / log(2);
 		sz++;
 		if (l > fpow(2, sz, LONG_LONG_MAX) - 1) {
 			cout << 0 << endl;
 			continue;
 		}
 		r = min(fpow(2, sz, LONG_LONG_MAX) - 1, r);
 		while (n) {
 			b.push_back(n);
 			n >>= 1;
 		}
 		ll ans = 0;
 		for (ll i = l ; i <= r; i++) {
 			if (i & 1) ans++;
 			else {
 				if ((i & i - 1) == 0) {
 					int idx = lower_bound(a.begin(), a.end(), i) - a.begin();
 					ans += (b[sz - idx - 1] & 1);
 				}
 				else {
 					ll k = i;
 					ll x = fpow(2, sz - 1, LONG_LONG_MAX);
 					if (k > x) {
 						k -= x;
 					}
 					while ((k & k - 1) != 0) {
 						int idx = upper_bound(a.begin(), a.end(), k) - a.begin() - 1;
 						k -= a[idx];
 					}
 					ans += (b[sz - (lower_bound(a.begin(), a.end(), k) - a.begin()) - 1] & 1);
 				}
 			}
 		}
 		cout << ans << endl;
 	}   
}