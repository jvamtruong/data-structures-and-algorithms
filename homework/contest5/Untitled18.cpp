#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

set < pair < pair < int, int >, int > > s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	s.insert(make_pair(make_pair(123, 8004), 765));
		s.insert(make_pair(make_pair(123, 8004), 765));
	cout << (*s.begin()).first.first << " " << (*s.begin()).first.second << " " << (*s.begin()).second << endl;
	pair < pair < int, int >, int > x;
	x = make_pair(make_pair(123, 8004), 765);
	cout << s.count(x);
}
