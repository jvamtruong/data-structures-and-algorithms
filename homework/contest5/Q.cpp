#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

priority_queue < long long , vector < long long > , greater < long long > > min_heap;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0 ; i < n; i++) {
			long long x;
			cin >> x;
			min_heap.push(x);
		}
		while (!min_heap.empty()) {
			cout << min_heap.top() << " ";
			min_heap.pop();
		}
		cout << endl;
	}
}
