#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

#define rd() (rand() << 15 | rand())
#define rd64() ((1ll * rd()) << 30 | (1ll * rd()))

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int roll(int x, int y) {
	return rd() % (y - x + 1) + x;
}

int64 roll64(int64 x, int64 y) {
	return rd64() % (y - x + 1) + x;
}

int main() {
	srand(time(0));
	freopen("2.in", "w", stdout);
	int n = 5;
	printf("%d\n", (1 << (n * (n + 1) / 2)) - 1);
	std::vector<PII> seg;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			seg.push_back({l, r});
		}
	}
	for (int i = 1; i < 1 << seg.size(); i++) {
		std::vector<PII> ans;
		for (int j = 0; j < seg.size(); j++) {
			if (i >> j & 1) {
				ans.push_back(seg[j]);
			}
		}
		printf("%d %d\n", n, ans.size());
		for (auto [x, y] : ans) {
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}