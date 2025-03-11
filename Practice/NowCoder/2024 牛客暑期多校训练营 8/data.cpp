#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {std::uniform_int_distribution<int64> dist(l, r); return dist(gen);}

const int mod = 1e9 + 7;

int main() {
	freopen("1.in", "w", stdout);
	int T = 100;
	std::cout << T << '\n';
	while (T--) {
		int64 n = roll(9e11, 1e12);
		std::cout << n << '\n';
	}
	return 0;
}