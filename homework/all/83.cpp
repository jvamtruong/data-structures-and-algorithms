#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int cnt[30];
priority_queue < int > max_heap;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		if (k > s.length()) {
			cout << 0 << endl;
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 0 ; i < s.length(); i++) {
			cnt[s[i] - 'A']++;
		}
		for (int i = 0 ; i < 26; i++) max_heap.push(cnt[i]);
		while (k--) {
			if (!max_heap.empty()) {
				int cur = max_heap.top();
				max_heap.pop();
				max_heap.push(cur - 1);
			}
		}
		long long ans = 0;
		while (!max_heap.empty()) {
			ans += max_heap.top() * max_heap.top();
			max_heap.pop();
		}
		cout << ans << endl;
	}		
}