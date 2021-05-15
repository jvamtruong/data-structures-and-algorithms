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
const int MAX = 1E5;

ll f[MAX + 5];
ll pref[MAX + 5];

// f[i] : so cach di tu bac 1 den bac i
// f[i] = f[i - 1] + f[i - 2] + .. f[i - k]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		pref[0] = 1;
		pref[1] = 2;
		f[1] = 1;
		for (int i = 2 ; i <= n; i++) {
			if (i - k - 1 >= 0) f[i] = (pref[i - 1] - pref[i - k - 1]) % MOD;
			else f[i] = pref[i - 1];
			if (f[i] < 0) f[i] += MOD;
			pref[i] = (pref[i - 1] + f[i]) % MOD;

		}
		cout << f[n] << endl;
	}  	
}	