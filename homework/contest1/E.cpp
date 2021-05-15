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


int a[20][20];
int x[20];
int sum[20];
int n, k;
bool mark[20];
int cnt = 0;

void printRes() {
	for (int i = 1 ; i <= n; i++) {
		cout << x[i] << " " ;
	}
	cout << endl;
}

void Try(int i) {
	for (int j = 1 ; j <= n; j++) {
		if (!mark[j]) {
			x[i] = j;
			sum[i] = sum[i - 1] + a[i][x[i]];
			if (i == n) {
				if (sum[i] == k) {
					cnt++;
				}
			}
			else {
				mark[j] = true;
				Try(i + 1);
				mark[j] = false;
			}
		}
	}
}

void _Try(int i) {
	for (int j = 1 ; j <= n; j++) {
		if (!mark[j]) {
			x[i] = j;
			sum[i] = sum[i - 1] + a[i][x[i]];
			if (i == n) {
				if (sum[i] == k) {
					printRes();
				}
			}
			else {
				mark[j] = true;
				_Try(i + 1);
				mark[j] = false;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	cin >> n >> k;
 	for (int i = 1 ; i <= n; i++) {
 		for (int j = 1 ; j <= n; j++) {
 			cin >> a[i][j];
 		}
 	}
 	Try(1);
 	cout << cnt << endl;
 	_Try(1);
}