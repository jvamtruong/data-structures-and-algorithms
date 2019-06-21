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

void fakeUpdate(int u, int v) {
    while (u <= n) {
        node[u].push_back(v);
        u += u & -u;
    }
}

void update(int u, int v, int val) {
    for (int x = u ; x <= n; x += x & -x) {
        for (int y = lower_bound(node[x].begin(), node[x].end(), v) - node[x].begin() + 1 ; y <= node[x].size(); y += y & -y) {
            fen[x][y] += val;
        }
    }
}

long long get(int u, int v) {
    long long res = 0;
    for (int x = u ; x > 0; x -= x & -x) {
        for (int y = upper_bound(node[x].begin(), node[x].end(), v) - node[x].begin() ; y > 0; y -= y & -y) {
            res += fen[x][y];
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
