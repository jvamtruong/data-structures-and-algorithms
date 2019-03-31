#include<bits/stdc++.h>
using namespace std;


//---https://www.spoj.com/PTIT/problems/P154SUMB/
//... use it on ranges like [1..1E9]

const int MAX = 1E9;

struct Node {
    int sum;
    Node *left, *right;
    Node() : sum(0), left(NULL), right(NULL) {} 
};

void update(Node *p, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (l == r) {
        p -> sum += val;
        return;
    }
    int m = l + r >> 1;
    if (p -> left == NULL) p -> left = new Node();
    if (p -> right == NULL) p -> right = new Node();
    update(p -> left, l, m, u, v, val);
    update(p -> right, m + 1, r, u, v, val);
    p -> sum = p -> left -> sum + p -> right -> sum;
}

int get(Node *p, int l, int r, int u, int v) {
    if (p == NULL || v < l || r < u) return 0;
    if (p && u <= l && r <= v) return p -> sum;
    int m = l + r >> 1;
    return get(p -> left, l, m, u, v) + get(p -> right, m + 1, r, u, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Node *root = new Node();
    long long ans = 0;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        ans += get(root, 1, MAX, x + 1, MAX);
        update(root, 1, MAX, x, x, 1);
    }
    cout << ans;
}
