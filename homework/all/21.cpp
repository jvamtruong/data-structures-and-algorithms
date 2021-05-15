#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

// f[n] = f[n - 1] + f[n - 2] + f[n - 3] + 2;

const long long MOD = 1E15 + 7;

long long f[10][10];
long long tmp[10][10] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 1}, {0, 0, 0, 1}};

long long mulMod(long long a, long long b) {
    if (b == 0) return 0;
    if (b == 1) return a % MOD;
    long long p = mulMod(a, b >> 1);
    if (b & 1) return (a + p + p) % MOD;
    else return (p + p) % MOD;
}

void mulMatrix(long long a[10][10], long long b[10][10]) {
    long long res[10][10];
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            for (int k = 0 ; k < 4; k++) {
                res[i][j] += mulMod(a[i][k], b[k][j]);
                res[i][j] %= MOD;
            }
        }
    }
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0 ; j < 4; j++) {
            f[i][j] = res[i][j];
        }
    }
}

void power(int n) {
    if (n == 1) {
        for (int i = 0 ; i < 4; i++) {
            for (int j = 0 ; j < 4; j++) {
                f[i][j] = tmp[i][j];
            }
        }
        return;
    }
    power(n >> 1);
    mulMatrix(f, f);
    if (n & 1) mulMatrix(f, tmp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            if (n == 1) cout << 1 << endl;
            if (n == 2) cout << 3 << endl;
            if (n == 3) cout << 6 << endl;
        }
        else {
            power(n - 3);
            cout << (f[2][0] + f[2][1] * 3 + f[2][2] * 6 + f[2][3] * 2) % MOD << endl;
        }
    }   
}