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


//-------------------------------------WA---------------------------------

const int MAX = 1E5;

int a[MAX + 5];
bool mark[MAX + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		for (int i = 0 ; i < n; i++) {
 			cin >> a[i];
 		}
 		memset(mark, false, sizeof mark);
 		sort(a, a + n);
 		int idx = -1;
 		for (int i = n - 1 ; i >= 0; i--) {
 			if (a[i] <= a[n - 1] / 2) {
 				idx = i;
 				break;
 			}
 		}
 		int l = idx;
 		int r = n - 1;
 		int ans = 0;
 		while (l >= 0 && l <= r) {
 			if (l == r) l--;
 			if (a[l] <= a[r] / 2) {
 				if (!mark[r]) {
 					if (!mark[l]) ans++;
 					mark[r] = true;
 					mark[l] = true;
 					l--;
 					r--;
 				}
 				else r--;
 			}
 			else l--;
 		}
 		cout << n - ans << endl;
 	}   
}