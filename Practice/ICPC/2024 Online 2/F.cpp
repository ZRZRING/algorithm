#include <bits/stdc++.h>

using int64 = long long;

int main() {
	int n;
	std::cin >> n;
	int64 s = 1500;
	for (int i = 1; i <= n; i++) {
		int64 x;
		std::cin >> x;
		s += x;
		if (s >= 4000) {
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << -1 << '\n';
}