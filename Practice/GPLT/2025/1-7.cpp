#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

int main() {
	int n;
	std::cin >> n;
	for (int p = 30; p >= 1; p--) {
		long long sum = 0, m;
		for (int i = 1; sum < n; i++) {
			long long t = i;
			for (int j = 2; j <= p; j++) {
				t *= i;
				if (t > n) break;
			}
			sum += t;
			m = i;
		}
		if (sum > n) {
			continue;
		}
		for (int i = 1; i <= m; i++) {
			std::cout << i << '^' << p << "+\n"[i == m];
		}
		return 0;
	}
	printf("Impossible for %d.\n", n);
}
