#include<bits/stdc++.h>
using namespace std;


//---https://vn.spoj.com/problems/NKINV/

const int MAX = 6 * 1E4;

int fen[MAX + 5];

void update(int x) {
    while (x <= MAX) {
        fen[x]++;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while (x) {
        res += fen[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > a(n + 5);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }       
    int ans = 0;
    for (int i = n - 1 ; i >= 0; i--) {
        ans += get(a[i] -  1); 
        update(a[i]);
    }
    cout << ans;
}
