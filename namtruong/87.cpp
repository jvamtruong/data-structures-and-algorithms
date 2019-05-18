#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < pair < int, int > > q;
set < int > s;
int a, b;

void bfs(int u) {
    q.push(make_pair(u, 0));
    s.insert(u);
    while (!q.empty()) {
        pair < int, int > cur = q.front();
        q.pop();
        if (cur.first == b) {
            cout << cur.second << endl;
            return;
        }
        if (!s.count(cur.first - 1)) {
            q.push(make_pair(cur.first - 1, cur.second + 1));
            s.insert(cur.first - 1);
        }
        if (cur.first * 2 > 10000) continue;
        if (!s.count(cur.first * 2)) {
            q.push(make_pair(cur.first * 2, cur.second + 1));
            s.insert(cur.first * 2);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        while (!q.empty()) q.pop();
        s.clear();
        bfs(a);
    }        
}