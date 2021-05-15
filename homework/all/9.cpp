#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < long long > q;
int n;

void bfs() {
    q.push(9);
    while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        if (cur % n == 0) {
            cout << cur << endl;
            return;
        }
        q.push(cur * 10);
        q.push(cur * 10 + 9);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        while (!q.empty()) q.pop();
        bfs();
    }
}