#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct data {
    int a[10][10];
    int cnt;
    data() {cnt = 0;}
};

data s, f;
queue < data > q;

void bfs() {
    q.push(s);
    while (!q.empty()) {
        data cur = q.front();
        q.pop();
        bool bl = false;
        for (int i = 0 ; i < 2; i++) {
            for (int j = 0 ; j < 3; j++) {
                if (cur.a[i][j] != f.a[i][j]) {
                    bl = true;
                    break;
                }
            }   
        }
        if (!bl) {
            cout << cur.cnt;
            return;
        }
        data l, r;
        for (int i = 0 ; i < 2; i++) {
            for (int j = 0 ; j < 3; j++) {
                l.a[i][j] = cur.a[i][j];
                r.a[i][j] = cur.a[i][j];
            }
        }
        int t = l.a[1][1];
        l.a[1][1] = l.a[0][1];
        l.a[0][1] = l.a[0][0];
        l.a[0][0] = l.a[1][0];
        l.a[1][0] = t;
        t = r.a[1][2];
        r.a[1][2] = r.a[0][2];
        r.a[0][2] = r.a[0][1];
        r.a[0][1] = r.a[1][1];
        r.a[1][1] = t;
        l.cnt = r.cnt = cur.cnt + 1;
        q.push(l);
        q.push(r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0 ; i < 2; i++) {
        for (int j = 0 ; j < 3; j++) {
            cin >> s.a[i][j];
        }
    }   
    for (int i = 0 ; i < 2; i++) {
        for (int j = 0 ; j < 3; j++) {
            cin >> f.a[i][j];
        }
    }
    bfs();
}