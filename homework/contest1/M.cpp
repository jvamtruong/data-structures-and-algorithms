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


ll f(ll x, ll y) {
    if (x == 0 && y == 0) return 0;
    if (x % 3 == 0 && y % 2 == 0) return f(x / 3, y / 2);
    if (x % 3 == 1 && y % 2 == 0) return f((x - 1) / 3, y / 2) + 1;
    if (x % 3 == 2 && y % 2 == 0) return f((x - 2) / 3, y / 2);
    if (x % 3 == 0 && y % 2 == 1) return f(x / 3, (y - 1) / 2) + 1;
    if (x % 3 == 1 && y % 2 == 1) return f((x - 1) / 3, (y - 1) / 2) + 2;
    if (x % 3 == 2 && y % 2 == 1) return f((x - 2) / 3, (y - 1) / 2) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;  
        cout << f(x, y) << endl;
    }
}