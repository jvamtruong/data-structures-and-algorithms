#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;

long long f[10][10];
long long tmp[10][10] = {{0, 1}, {1, 1}};

void mul(long long a[10][10], long long b[10][10]) {
    long long res[10][10];
    for (int i = 0 ; i <= 1; i++) {
        for (int j = 0 ; j <= 1; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0 ; i <= 1; i++) {
        for (int j = 0 ; j <= 1; j++) {
            for (int k = 0 ; k <= 1; k++) {
                res[i][j] += a[i][k] * b[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    for (int i = 0 ; i <= 1; i++) {
        for (int j = 0 ; j <= 1; j++) {
            f[i][j] = res[i][j];
        }
    }
}

void power(int n) {
    if (n == 1 || n == 0) {
        f[0][0] = 0;
        f[0][1] = f[1][0] = f[1][1] = 1;
        return;
    }
    power(n >> 1);
    mul(f, f);
    if (n & 1) mul(f, tmp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        power(n - 1);
        cout << f[1][1] << endl;
    }       
}