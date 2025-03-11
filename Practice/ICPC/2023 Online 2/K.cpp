#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int64, int64>
#define l first
#define r second

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const long double eps = 1e-10;

int main() {
	int T = read();
	while (T--) {
		int64 a = read(), b = read(), n = read();
		a %= n; b %= n;
		int64 ans = a * a + b * b;
		std::set<PII> vis;
		vis.emplace(0, 0);
		int64 x = a, y = b;
		while (1) {
			if (vis.count({x, y})) break;
			vis.emplace(x, y);
			int64 t = std::min((n - x + a - 1) / a, (n - y + b - 1) / b);
			x = (x + t * a) % n; y = (y + t * b) % n;
			if (x == 0 && y == 0) break;
			if (x >= 2e2) continue;
			if (y >= 2e2) continue;
			ans = std::min(ans, x * x + y * y);
		}
		printf("%lld %d\n", ans, vis.size());
	}
	return 0;
}