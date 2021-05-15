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

ll f[5000][5000];

int main() {
    ios_base::sync_with_stdio(0);
   	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0 ; i <= n; i++) {
			for (int j = 0 ; j <= k; j++) {
				f[i][j] = 0;
			}
		}
		if (k == 0) {
			if (n == 1) cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		if (k > 9 * n) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1 ; i <= 9; i++) f[1][i] = 1;
		for (int i = 2 ; i <= n; i++) {
			for (int j = 1 ; j <= k; j++) {
				for (int digit = 0 ; digit <= 9; digit++) {
					if (digit <= j) {
						f[i][j] += f[i - 1][j - digit] % MOD;
						f[i][j] %= MOD;
					}
				}
			}
		}
		cout << f[n][k] << endl;
	}
}