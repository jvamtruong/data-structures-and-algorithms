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

// dp + bitmask
// O((n ^ 2) * (2 ^ n))

int getBit(int j, int i) {
    return (i >> j - 1) & 1;
}

int offBit(int j, int i) {
    return i ^ (1 << j - 1);
}

int a[20][20];
ll f[1 << 16][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--) {
         int n;
        cin >> n;
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1 ; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1 ; i < (1 << n); i++) {
            for (int j = 1 ; j <= n; j++) {
                f[i][j] = INT_MAX;
            }
        }
        for (int state = 1 ; state < (1 << n); state++) {
            for (int i = 1 ; i <= n; i++) {
                if (getBit(i, state)) {
                    int pre_state = offBit(i, state);
                    if (pre_state == 0) {
                        f[state][i] = 0;
                        continue;
                    }
                    for (int j = 1; j <= n; j++) {
                        if (j != i && getBit(j, state)) {
                            f[state][i] = min(f[state][i], f[pre_state][j] + a[j][i]);
                        }
                    }
                }
            }
        }   
        int ans = INT_MAX;
        for (int i = 1 ; i <= n; i++) {
            ans = min(ans, f[(1 << n) - 1][i]);
        }
        cout << ans << endl;
    }
}