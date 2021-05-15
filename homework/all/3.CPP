#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x[100];
int cnt[100];
int n, k;

bool isFinal() {
    for (int i = 1 ; i <= k; i++) {
        if (x[i] != n - k + i) return false;
    }
    return true;
}

void genNext() {
    int i = k;
    while (x[i] == n - k + i) i--;
    x[i]++;
    for (int j = i + 1 ; j <= k; j++) {
        x[j] = x[j - 1] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1 ; i <= k; i++) {
            cin >> x[i];
            cnt[x[i]]++;
        }
        if (isFinal()) cout << k << endl;
        else {
            genNext();
            int ans = 0;
            for (int i = 1 ; i <= k; i++) {
                ans += (cnt[x[i]] == 0);
            }
            cout << ans << endl;
        }
    }
}