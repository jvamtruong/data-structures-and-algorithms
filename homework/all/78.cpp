#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E4;

queue < pair < int, int > > q;
bool mark[MAX + 5];
bool visit[MAX + 5];
int a, b;

void sieve() {
    for (int i = 2 ; i <= 100; i++) {
        if (!mark[i]) {
            for (int j = i * i ; j <= MAX; j += i) {
                mark[j] = true;
            }
        }
    }
}

void bfs(int u) {
    q.push(make_pair(u, 0));
    visit[u] = true;
    while (!q.empty()) {
        pair < int, int > cur = q.front();
        q.pop();
        if (cur.first == b) {
            cout << cur.second << endl;
            return;
        }
        vector < int > v;
        v.clear();
        int n = cur.first;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        for (int i = 3 ; i >= 0; i--) {
            for (int j = (i == 3) ? 1 : 0 ; j <= 9; j++) {
                int val = 0;
                for (int k = 3 ; k >= 0; k--) {
                    if (k != i) val = val * 10 + v[k];
                    else val = val * 10 + j;
                }
                if (!visit[val] && !mark[val]) {
                    q.push(make_pair(val, cur.second + 1));
                    visit[val] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    sieve();
    while (t--) {
        cin >> a >> b;
        memset(visit, false, sizeof visit);
        while (!q.empty()) q.pop();
        bfs(a);
    }         
}