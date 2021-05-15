#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int x[100];
bool mark[100];
int cnt[30][30];
int ans = 1E9;


void process() {
    int res = 0;
    for (int i = 1 ; i < n; i++) {
        for (int j = 0 ; j < 26; j++) {
            if (cnt[x[i]][j] && cnt[x[i + 1]][j]) res++;
        }
    }
    ans = min(ans, res);
}

void Try(int i) {
    for (int j = 1 ; j <= n; j++) {
        if (!mark[j]) {
            x[i] = j;
            mark[j] = true;
            if (i == n) process();
            else Try(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < s.length(); j++) {
            cnt[i][s[j] - 'A']++;
        }
    }    
    Try(1);
    cout << ans;
}