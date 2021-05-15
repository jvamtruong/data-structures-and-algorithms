#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;

long long f[100][100];
long long tmp[100][100];
int n, k;

void mul(long long a[100][100], long long b[100][100]) {
    long long res[100][100];
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            for (int k = 0 ; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            f[i][j] = res[i][j];
        }
    }
}

void power(int k) {
    if (k == 0 || k == 1) {
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                f[i][j] = tmp[i][j];
            }
        }
        return;
    }
    power(k >> 1);
    mul(f, f);
    if (k & 1) mul(f, tmp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cin >> tmp[i][j];
            }
        }
        power(k);
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
    }
}