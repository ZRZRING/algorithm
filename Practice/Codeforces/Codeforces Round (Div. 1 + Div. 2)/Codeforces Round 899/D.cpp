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

const int64 mod = 998244353;

void solve() {
	int n = read();
	int64 a[n + 1];
	for (int i = 1; i <= n; i++) a[i] = read();
	std::vector<int> edge[n + 1];
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int64 size[n + 1] = {0}, ans[n + 1] = {0};
	std::function<void(int, int)> dfs1 = [&](int u, int fa) -> void {
		size[u] = 1;
		for (auto v : edge[u]) {
			if (v == fa) continue;
			dfs1(v, u);
			size[u] += size[v];
			ans[u] += ans[v] + size[v] * (a[u] ^ a[v]);
		}
	};
	std::function<void(int, int)> dfs2 = [&](int u, int fa) -> void {
		ans[u] += ans[fa] - ans[u] - size[u] * (a[u] ^ a[fa]) + (a[u] ^ a[fa]) * (n - size[u]);
		for (auto v : edge[u]) {
			if (v == fa) continue;
			dfs2(v, u);
		}
	};
	dfs1(1, 1);
	// for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); puts("");
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); puts("");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}