#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

// https://vn.spoj.com/problems/KGSS/
 
const int MAX = 1E5;
 
int node[4 * MAX + 5];
int a[MAX + 5];
 
void build(int k, int l, int r) {
    if (l == r) {
        node[k] = r;
        return;
    }
    int m = l + r >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    if (a[node[k << 1]] >= a[node[k << 1 | 1]]) node[k] = node[k << 1];
    else node[k] = node[k << 1 | 1];
}
 
void update(int k, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        a[r] = val;
        return;
    }
    int m = l + r >> 1;
    update(k << 1, l, m, u, v, val);
    update(k << 1 | 1, m + 1, r, u, v, val);
    if (a[node[k << 1]] >= a[node[k << 1 | 1]]) node[k] = node[k << 1];
    else node[k] = node[k << 1 | 1];
}
 
int get(int k, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return node[k];
    int m = l + r >> 1;
    int left = get(k << 1, l, m, u, v);
    int right = get(k << 1 | 1, m + 1, r, u, v);
    if (a[left] >= a[right]) return left;
    else return right;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a[0] = INT_MIN;
    for (int i = 1 ; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        char t;
        cin >> t;
        if (t == 'U') {
            int u, v;
            cin >> u >> v;
            update(1, 1, n, u, u, v);
        }
        else {
            int u, v;
            cin >> u >> v;
            int x = get(1, 1, n, u, v);
            int temp = a[x];
            update(1, 1, n, x, x, a[0]);
            int y = get(1, 1, n, u, v);
            cout << temp + a[y] << endl;
            update(1, 1, n, x, x, temp);
        }
    }
} 
