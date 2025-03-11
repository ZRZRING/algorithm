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
	for (int i = 11; i <= 11; i++) {
		freopen((std::to_string(i) + ".in").c_str(), "w", stdout);
		int n = 16, m = 200;
		printf("%d %d\n", n, m);
		std::vector<int> a(n * n);
		std::iota(a.begin(), a.end(), 0);
		std::random_shuffle(a.begin(), a.end());
		for (int i = 1, j = 1; j <= m; i++, j++) {
			if (a[i] % n == a[i] / n) {j--; continue;}
			printf("%d %d %d\n", a[i] % n + 1, a[i] / n + 1, roll(1, 100));
		}
	}
	return 0;
}