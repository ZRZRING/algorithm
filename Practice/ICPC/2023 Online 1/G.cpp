#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 998244353, N = 1e6 + 10;

int64 qpow(int64 a, int64 x = mod - 2) {
	int64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int n = read();
	std::vector<int> fa(2 * n + 1), sz(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) fa[i] = i, sz[i] = 1;
	int64 ans = 0;
	std::vector<int> t1[n + 1], box[n + 1];
	int time = 0;
	std::function<void(int, int, int)> dfs = [&](int x, int u, int last) -> void {
		box[x].push_back(u);
		for (auto v : t1[u]) {
			if (v == last) continue; dfs(x, v, u);
		}
	};
	std::function<int(int)> find = [&](int x) -> int {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	};
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		int X = find(u), Y = find(v);
		t1[X].push_back(Y);
		t1[Y].push_back(X);
		if (X != Y) {
			fa[X] = Y;
			ans = (ans + 1ll * sz[X] * sz[Y] % mod) % mod;
			if (sz[X] < sz[Y]) dfs(i, X, 0); else dfs(i, Y, 0);
			sz[X] += sz[Y];
		} else {
			printf("0\n"); return 0;
		}
	}
	std::vector<int> t2[n + 1];
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		t2[u].push_back(v);
		t2[v].push_back(u);
	}
	std::vector<int> vis(n + 1);
	int cnt = 0;
	std::function<void(int)> check = [&](int u) -> void {
		vis[u] = 0; cnt--;
		for (auto v : t2[u]) {
			if (vis[v]) check(v);
		}
	};
	for (int i = 1; i < n; i++) {
		for (auto x : box[i]) {
			vis[x] = 1; cnt++;
		}
		check(box[i][0]);
		if (cnt != 0) {
			printf("0\n"); return 0;
		}
	}
	printf("%lld\n", qpow(ans));
	return 0;
}