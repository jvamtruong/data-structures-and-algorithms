#include<bits/stdc++.h>
#define endl '\n'
#define div ___div
using namespace std;

// f[i][j] : so nho nhat co i uoc va duoc tao thanh tu j snt dau tien
// f[i][j] = f[i / (k + 1)][j - 1] * fpow(p[j], k) (k + 1 la cac uoc cua i)
 
const int MAX = 1E3;
const long long INF = 1E18;
 
long long f[MAX + 5][15];
int p[15] = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector < int > div[MAX + 5];
 
long long fpow(int a, int b) {
    long long res = 1;
    for (int i = 0 ; i < b; i++) res *= a;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1 ; i <= MAX; i++) {
        for (int j = 1 ; j <= sqrt(MAX); j++) {
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
            f[i][1] = 1ll << i - 1;
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