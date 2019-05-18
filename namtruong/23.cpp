#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int xmin = 1E9;
    int ymin = 1E9;
    while (n--) {
        int x, y;
        cin >> x >> y;
        xmin = min(xmin, x);
        ymin = min(ymin, y);
    }    
    cout << 1ll * xmin * ymin;
}