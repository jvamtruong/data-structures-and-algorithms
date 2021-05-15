#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < string > q;
int n;

void bfs() {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    while (!q.empty()) q.pop();
    q.push("1");
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        int res = 0;
        for (int i = 0 ; i < cur.length(); i++) {
            res = res * 10 + (cur[i] - '0');
            res %= n;
        }
        if (res == 0) {
            cout << cur << endl;
            return;
        }
        q.push(cur + "0");
        q.push(cur + "1");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        bfs();
    }
}