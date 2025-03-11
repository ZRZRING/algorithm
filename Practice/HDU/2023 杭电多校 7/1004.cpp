#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), ans = 0;
		if (n <= 3) {printf("1\n"); continue;}
		auto get = [&](int x) -> int {
			return n / (2 * x + 2) * 2 + std::max(0, n % (2 * x + 2) - 2 * x);
		};
		for (int i = sqrt(n) - 200; i <= sqrt(n) + 200; i++) {
			if (i <= 0) continue;
			if (i == get(i)) {ans = i; break;}
			if (i < get(i) && i + 1 > get(i + 1)) {ans = i + 1; break;}
		}
		printf("%d\n", ans);
	}
	return 0;
}