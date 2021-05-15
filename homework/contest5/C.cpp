#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

deque < int > dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "PUSHBACK") {
			int val;
			cin >> val;
			dq.push_back(val);
		}
		if (s == "PRINTBACK") {
			if (!dq.empty()) cout << dq.back() << endl;
			else cout << "NONE" << endl;
		}
		if (s == "PUSHFRONT") {
			int val;
			cin >> val;
			dq.push_front(val);
		}
		if (s == "PRINTFRONT") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			}
			else cout << "NONE" << endl;
		}
		if (s == "POPBACK") {
			if (!dq.empty()) dq.pop_back();
		}
		if (s == "POPFRONT") {
			if (!dq.empty()) dq.pop_front();
		}
	}
}
