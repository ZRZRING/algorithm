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

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int gcd(int a, int b) {
	if (a < b) std::swap(a, b);
	return b ? gcd(b, a % b) : a;
}

int main() {
	int T = read();
	while (T--) {
		int k = read(), c = read(), n = read();
		int ans = 0;
		for (int b = 1, a; b * b <= c; b++) {
			if (c % b != 0) continue;
			if (c - b != 0 && (c - b) % k == 0 && gcd((c - b) / k, b) >= n) ans++;
			int tb = c / b, t = b; if (tb == b) continue; b = tb;
			if (c - b != 0 && (c - b) % k == 0 && gcd((c - b) / k, b) >= n) ans++;
			b = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}