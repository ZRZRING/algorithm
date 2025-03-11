#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

int main() {
	int n = roll(1, 10);
	std::cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		std::cout << roll(1, 10) << " \n"[i == n];
	}
	for (int i = 2; i <= n; i++) {
		std::cout << i << ' ' << roll(1, i - 1) << '\n';
	}
	return 0;
}