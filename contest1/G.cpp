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


map < int, bool > a, b, c;
int n = 8;
int val[10][10];
int sum[10];
int ans = -1;

void Try(int i) {
	for (int j = 1 ; j <= n; j++) {
		if (!c[j] && !a[i + j] && !b[i - j]) {
			sum[i] = sum[i - 1] + val[i][j];
			c[j] = true;
			a[i + j] = true;
			b[i - j] = true;
			if (i == n) ans = max(ans, sum[i]);
			else Try(i + 1);
			c[j] = false;
			a[i + j] = false;
			b[i - j] = false;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	ans = -1;
    	a.clear();
    	b.clear();
    	c.clear();
   	 	for (int i = 1 ; i <= n; i++) {
    		for (int j = 1 ; j <= n; j++) {
    			cin >> val[i][j];
    		}
    	}
    	Try(1);
    	cout << ans << endl;
    }
}