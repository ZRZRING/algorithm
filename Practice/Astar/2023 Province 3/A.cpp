#include <bits/stdc++.h>

#define A10 std::array<int64, 10>

using int64 = long long;

const int64 mod = 1e9 + 7;

template<class T>
T MOD(T &x, T p = mod) {
	return x = (x % p + p) % p;
}
template<class T>
T MOD(T &&x, T p = mod) {
	return x = (x % p + p) % p;
}

int main() {
	int64 n;
	std::cin >> n;
	std::vector<A10> f(n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		MOD(f[i][0] = f[i - 1][0] * 25 + f[i - 1][1] * 24 + f[i - 1][2] * 25);
		MOD(f[i][1] = f[i - 1][0] + f[i - 1][1]);
		MOD(f[i][2] = f[i - 1][1]);
		MOD(f[i][3] = f[i - 1][2] + f[i - 1][3] * 25 + f[i - 1][4] * 24 + f[i - 1][5] * 25);
		MOD(f[i][4] = f[i - 1][3] + f[i - 1][4]);
		MOD(f[i][5] = f[i - 1][4]);
		MOD(f[i][6] = f[i - 1][5] + f[i - 1][6] * 25 + f[i - 1][7] * 24 + f[i - 1][8] * 25);
		MOD(f[i][7] = f[i - 1][6] + f[i - 1][7]);
		MOD(f[i][8] = f[i - 1][7]);
		MOD(f[i][9] = f[i - 1][8] + f[i - 1][9] * 26);
	}
	std::cout << f[n][9] << '\n';
}