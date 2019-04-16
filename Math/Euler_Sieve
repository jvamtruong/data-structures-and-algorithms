// Time complexity : O(nlog(n))

void eulerSieve(int n) {
	for (int i = 2 ; i <= n; i++) phi[i] = i;
	for (int i = 2 ; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i ; j <= n; j++) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}
