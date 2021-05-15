#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E7;

queue < pair  < int, int > > q;
bool mark[MAX + 5];

void bfs(int u) {
    q.push(make_pair(u, 0));
    mark[u] = true;
    while (!q.empty()) {
        pair < int, int > cur = q.front();
        q.pop();
        int n = cur.first;
        int cnt = cur.second;
        if (n == 1) {
            cout << cnt << endl;
            return;
        }
        if (!mark[n - 1]) {
            q.push(make_pair(n - 1, cnt + 1));
            mark[n - 1] = true;
        }
        for (int i = 2 ; i <= sqrt(n); i++) {
            if (n % i == 0) {
                int u = i;
                int v = n / i;
                int val = max(u, v);
                if (!mark[val]) {
                    q.push(make_pair(val, cnt + 1));
                    mark[val] = true;
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
    while (t--) {
        int n;
        cin >> n;
        memset(mark, false, sizeof mark);
        while (!q.empty()) q.pop();
        bfs(n);
    }
}