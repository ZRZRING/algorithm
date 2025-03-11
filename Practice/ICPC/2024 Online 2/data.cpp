#include <bits/stdc++.h>

using int64 = long long;

#define A3 std::array<int64, 3>

int main() {
	freopen("L.in", "w", stdout);
	int T = 1e6;
	std::cout << T << '\n';
	for (int i = 1e9 - T; i <= 1e9; i++) {
		std::cout << i << '\n';
	}
}