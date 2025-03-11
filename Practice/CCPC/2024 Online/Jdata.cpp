#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll (int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

int main() {
	int T = 10;
	std::cout << T << '\n';
	while (T--) {
		int n = roll(1, 8);
		std::cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			std::cout << roll(1, 15) << " \n"[i == n];
		}
		for (int i = 1; i <= n; i++) {
			std::cout << roll(1, 15) << " \n"[i == n];
		}
	}
}