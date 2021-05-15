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


// f[i][j] : so nho nhat co i uoc va duoc tao thanh tu j snt dau tien
// f[i][j] = f[i / (k + 1)][j - 1] * fpow(p[j], k) (k + 1 la cac uoc cua i)

const int MAX = 1E3;
const ll INF = 1E18;

ll f[MAX + 5][15];
int p[15] = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vi div[MAX + 5];

ll fpow(int a, int b) {
    ll res = 1;
    for (int i = 0 ; i < b; i++) res *= a;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1 ; i <= MAX; i++) {
        for (int j = 1 ; j <= sqrt(i); j++) {
            if (i % j == 0) {
                div[i].push_back(j);
                if (i / j != j) div[i].push_back(i / j);
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1 ; i <= MAX; i++) {
            for (int j = 1 ; j <= 10; j++) {
             if (i == 1) f[i][j] = 1;
                else f[i][j] = LONG_LONG_MAX;
            }
        }
        for (int i = 1 ; i <= 60; i++) {
            f[i][1] = fpow(2, i - 1);
        }
        for (int i = 2 ; i <= n; i++) {
            for (int j = 2 ; j <= 10; j++) {
                for (int k = 0 ; k < div[i].size(); k++) {
                    int x = log(INF) / log(p[j]);
                    x++;
                    if (div[i][k] - 1 < x) {
                        if (f[i / div[i][k]][j - 1] < INF / fpow(p[j], div[i][k] - 1)) {
                            f[i][j] = min(f[i][j], f[i / div[i][k]][j - 1] * fpow(p[j], div[i][k] - 1));
                        }
                    }  
                }
            }
        }
        cout << f[n][10] << endl;
    }
}