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

void solve() {
	int n = read(), m = read();
	std::vector<std::array<int64, 3> > edge(m + 1);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), t = read();
		edge[i] = {t, u, v};
	}
	sort(edge.begin() + 1, edge.end());
	std::vector<int> fa(n + 1), size(n + 1, 1);
	std::iota(fa.begin(), fa.end(), 0);
	auto find = [&](auto self, int x) -> int {
		return fa[x] == x ? x : fa[x] = self(self, fa[x]);
	};
	int64 ans = 0;
	for (int i = 1; i <= m; i++) {
		auto [t, x, y] = edge[i];
		x = find(find, x);
		y = find(find, y);
		if (x == y) continue;
		ans += size[x] * size[y] * t;
		fa[y] = x;
		size[x] += size[y];
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = find(find, i);
		if (fa[i] != fa[1]) {
			printf("-1\n"); return;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int T = 1;
	while (T--) solve();
	return 0;
}