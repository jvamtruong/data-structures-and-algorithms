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


const int MOD = 1E9 + 7;

ll tmp[10][10] = {{0, 1}, {1, 1}};
ll f[10][10];

void mul(ll a[10][10], ll b[10][10]) {
	ll res[10][10];
	res[0][0] = res[0][1] = res[1][0] = res[1][1] = 0;
	for (int i = 0 ; i <= 1; i++) {
		for (int j = 0 ; j <= 1; j++) {
			for (int k = 0 ; k <= 1; k++) {
				res[i][j] += a[i][k] * b[k][j] % MOD;
				res[i][j] %= MOD;
			}
		}
	}
	for (int i = 0 ; i <= 1; i++) {
		for (int j = 0 ; j <= 1; j++) {
			f[i][j] = res[i][j];
		}
	}
}

void power(int n) {
	if (n == 1) {
		f[0][0] = 0;
		f[0][1] = f[1][0] = f[1][1] = 1;
		return;
	}
	power(n >> 1);
	mul(f, f);
	if (n & 1) mul(f, tmp);	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 2) cout << 1 << endl;
		else {
			power(n - 2);
			cout << (f[1][0] + f[1][1]) % MOD << endl;
		}
	}
}