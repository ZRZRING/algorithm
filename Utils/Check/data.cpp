#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

int main() {
	int T = 10;
	std::cout << T << '\n';
	while (T--) {
		int l = roll(1, 50), r = roll(1, 50);
		if (l > r) std::swap(l, r);
		std::cout << l << ' ' << r << '\n';
	}
	return 0;
}