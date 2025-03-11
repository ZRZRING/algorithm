#include <bits/stdc++.h>

using int64 = long long;

int64 rnd() {
	return 1ll * rand() << 15 | rand();
}

int64 rd() {
	return 1ll * rnd() << 30 | rnd();
}

int64 roll(int64 l, int64 r) {
	return (rd() % (r - l + 1)) + l;
}

int main() {
	srand(time(0));
	int T = 10;
	std::cout << T << '\n';
	while (T--) {
		int n = roll(1, 10), k = roll(1, n), d = roll(1, 10);
		std::cout << n << ' ' << k << ' ' << d << '\n';
		for (int i = 1; i <= n; i++) {
			std::cout << roll(1, 10) << ' ';
		}
		std::cout << '\n';
	}
}