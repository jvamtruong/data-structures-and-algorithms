#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//  https://www.spoj.com/PTIT/problems/P144SUMJ/

const int MAX = 1E5;

struct Query {
    char type;
    int x, y, z, t;
};

int n, m;
vector < int > node[MAX + 5];
vector < long long > fen[MAX + 5];

void fakeUpdate(int x, int y) {
    while (x <= n) {
        node[x].push_back(y);
        x += x & -x;
    }
}

void update(int x, int y, int val) {
    for (int u = x ; u <= n; u += u & -u) {
        for (int v = lower_bound(node[u].begin(), node[u].end(), y) - node[u].begin() + 1 ; v <= node[u].size(); v += v & -v) {
            fen[u][v] += val;
        }
    }
}

long long get(int x, int y) {
    long long res = 0;
    for (int u = x ; u > 0; u -= u & -u) {
        for (int v = upper_bound(node[u].begin(), node[u].end(), y) - node[u].begin() ; v > 0; v -= v & -v) {
            res += fen[u][v];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector < Query > a(m + 5);
    for (int i = 1 ; i <= m; i++) {
        cin >> a[i].type >> a[i].x >> a[i].y >> a[i].z;
        if (a[i].type == 'S') fakeUpdate(a[i].x, a[i].y);
        else cin >> a[i].t;
    }
    for (int i = 1 ; i <= n; i++) {
        sort(node[i].begin(), node[i].end());
        fen[i].resize(node[i].size() + 3);
    }
    for (int i = 1 ; i <= m; i++) {
        if (a[i].type == 'S') update(a[i].x, a[i].y, a[i].z);
        else cout << get(a[i].z, a[i].t) - get(a[i].z, a[i].y - 1) - get(a[i].x - 1, a[i].t) + get(a[i].x - 1, a[i].y - 1) << endl;
    }
}
