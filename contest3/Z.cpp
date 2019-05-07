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


const int MAX = 1E4;

ll f[1 << 5][MAX + 5];
ll sum[1 << 5][MAX + 5];
ll a[10][MAX + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	for (int i = 1 ; i <= 4; i++) {
    		for (int j = 1 ; j <= n; j++) {
    			cin >> a[i][j];
    		}
    	}
    	for (int i = 0 ; i < (1 << 4); i++) {
    		for (int j = 1 ; j <= n; j++) {
    			sum[i][j] = 0;
    			f[i][j] = 0;
    		}
    	}
    	for (int i = 1 ; i <= n; i++) {
    		for (int mask = 1 ; mask < (1 << 4); mask++) {
    			if (mask & (mask >> 1)) continue;
    			else {
    				int cnt = 1;
    				int j = mask;
    				while (j) {
    					sum[mask][i] += (j & 1) * a[cnt][i];
    					j >>= 1;
    					cnt++;
    				}
    			}
    		}
    	}
    	for (int i = 1 ; i <= n; i++) {
    		for (int mask = 0 ; mask < (1 << 4); mask++) {
    			if (mask & (mask >> 1)) continue;
    			else {
    				for (int _mask = 0 ; _mask < (1 << 4); _mask++) {
    					if (_mask & (_mask >> 1)) continue;
    					else {
    						if (_mask & mask) continue;
    						else {
    							f[mask][i] = max(f[mask][i], f[_mask][i - 1] + sum[mask][i]);
    						}
    					}	
    				}
    			}
    		}
    	}
    	ll ans = 0;
    	for (int mask = 0 ; mask < (1 << 4); mask++) {
    		if (mask & (mask >> 1)) continue;
    		else ans = max(ans, f[mask][n]);
    	}
    	if (ans == 0) {
    		ll final_ans = LONG_LONG_MIN;
    		for (int i = 1 ; i <= 4; i++) {
    			for (int j = 1 ; j <= n; j++) {
    				final_ans = max(final_ans, a[i][j]);
    			}
    		}
    		cout << final_ans << endl;
    	}
    	else cout << ans << endl;
    }
}