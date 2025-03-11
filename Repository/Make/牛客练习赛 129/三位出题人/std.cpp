#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 1e9 + 7;

int64 qpow(int64 a, int64 x) {
	int64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int T = read();
	while (T--) {
		int64 n = read(), m = read();
		printf("%lld\n", qpow(qpow(2, m) - 2, n));
	}
	return 0;
}