#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound 
#define div         ___div
#define left        ___left
#define right       ___right
#define bitcount(x) __builtin_popcountll(x)
#define all(x)     x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<plll> vlll;
typedef vector<char> vc;
inline ll max(ll a, ll b) {return a < b ? b : a;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b;a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a * (b / gcd(a, b));}
inline ll fpow(ll a, ll b, ll m) {ll r = 1; while (b) {if (b & 1) r = (r % m) * a % m; a %= m; a = a * a % m; b >>= 1;} return r;}


const ll MOD = 1E15 + 7;

ll tmp[10][10] = {{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}};
ll f[10][10];

ll mulMod(ll a, ll b) {
	if (b == 0) return 0;
	if (b == 1) return a % MOD;
	ll p = mulMod(a, b >> 1);
	if (b & 1) return (p + p + a) % MOD;
	else return (p + p) % MOD;
}

void mulMatrix(ll a[10][10], ll b[10][10]) {
	ll res[10][10];
	for (int i = 0 ; i < 4; i++) {
		for (int j = 0 ; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	for (int i = 0 ; i < 4; i++) {
		for (int j = 0 ; j < 4; j++) {
			for (int k = 0 ; k < 4; k++) {
				res[i][j] += mulMod(a[i][k], b[k][j]);
				res[i][j] %= MOD;
			}
		}
	}
	for (int i = 0 ; i < 4; i++) {
		for (int j = 0 ; j < 4; j++) {
			f[i][j] = res[i][j];
		}
	}
}

void power(int n) {
	if (n == 1) {
		for (int i = 0 ; i < 4; i++) {
			for (int j = 0 ; j < 4; j++) {
				f[i][j] = tmp[i][j];
			}
		}
		return;
	}
	power(n >> 1);
	mulMatrix(f, f);
	if (n & 1) mulMatrix(f, tmp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		if (n <= 3) {
 			if (n == 1) cout << 1 << endl;
 			if (n == 2) cout << 3 << endl;
 			if (n == 3) cout << 6 << endl;
 			continue;
 		}
 		power(n - 3);
 		ll ans = (f[0][0] * 6 + f[0][1] * 3 + f[0][2] + f[0][3] * 2) % MOD;
 		cout << ans << endl;
 	}
}