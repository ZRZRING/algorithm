#include <bits/stdc++.h>

using int64 = long long;

#define A3 std::array<int64, 3>

const int64 mod = 998244353;

int64 qpow(int64 a, int64 x = mod - 2) {
	a %= mod;
	x %= mod - 1;
	int64 res = 1;
	while (x) {
		if (x & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

int main() {
	std::cout <<99824436ll * 10ll % mod << '\n';
}