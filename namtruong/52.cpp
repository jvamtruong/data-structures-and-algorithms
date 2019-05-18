#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E6;
const int BASE = 311;

int hashP[MAX + 5];
int pw[MAX + 5];
string p, t;

int getHashP(int i, int j) {
    return hashP[j] - hashP[i -1] * pw[j - i + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> p >> t;
        if (p.length() < t.length()) cout << "NO" << endl;
        else {
            int m = p.length();
            int n = t.length();
            p.insert(0, " ");
            t.insert(0, " ");
            int hashT = 0;
            for (int i = 1 ; i <= n; i++) {
                hashT = hashT * BASE + t[i];
            }
            pw[0] = 1;
            for (int i = 1 ; i <= m; i++) {
                pw[i] = pw[i - 1] * BASE;
                hashP[i] = hashP[i - 1] * BASE + p[i];
            }
            bool bl = false;
            for (int i = 1 ; i <= m - n + 1; i++) {
                if (hashT == getHashP(i, i + n - 1)) {
                    bl = true;
                    cout << "YES" << endl;
                }
            }
            if (!bl) cout << "NO" << endl;
        }
    }      
}