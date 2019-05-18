#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[1 << 16][20];
int c[20][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int mask = 1 ; mask < (1 << n); mask++) {
        for (int i = 1 ; i <= n; i++) {
            f[mask][i] = 1E9;
        }
    }        
    f[1][1] = c[1][1];
    for (int mask = 2 ; mask < (1 << n); mask++) {
        for (int i = 1 ; i <= n; i++) {
            if ((mask >> i - 1) & 1) {
                for (int j = 1 ; j <= n; j++) {
                    if (j != i && ((mask >> j - 1) & 1)) {
                        int newMask = mask ^ (1 << i - 1);
                        f[mask][i] = min(f[mask][i], f[newMask][j] + c[j][i]);
                    }
                }
            }
        }
    }
    int ans = 1E9;
    for (int i = 1 ; i <= n; i++) {
        ans = min(ans, f[(1 << n) - 1][i] + c[i][1]);
    }
    cout << ans;
}