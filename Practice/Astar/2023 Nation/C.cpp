#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define int64 long long
#define endl '\n'

const int mod = 1e8 + 7;

int qpow(int a, int x = mod - 2) {
	int res = 1;
	while (x) {
		if (x & 1) {
			res = 1ll * res * a % mod;
		}
		a = 1ll * a * a % mod;
		x >>= 1;
	}
	return res;
}

struct SEG {
	#define ls x << 1
	#define rs x << 1 | 1

	int n;

	std::vector<int> sum, tag;

	SEG(int m) {
		n = m;
		sum.resize(n * 4 + 1);
		tag.resize(n * 4 + 1);
		for (int i = 1; i <= n * 4; i++) {
			tag[i] = 1;
		}
	}

	void pushdown(int x) {
		sum[ls] = 1ll * sum[ls] * tag[x] % mod;
		sum[rs] = 1ll * sum[rs] * tag[x] % mod;
		tag[ls] = 1ll * tag[ls] * tag[x] % mod;
		tag[rs] = 1ll * tag[rs] * tag[x] % mod;
		tag[x] = 1;
	}

	void modify(int x, int l, int r, int pos, int t) {
		if (l == r) {
			sum[x] = (sum[x] + t) % mod;
			return;
		}
		int mid = l + r >> 1;
		pushdown(x);
		if (mid >= pos) modify(ls, l, mid, pos, t);
		else modify(rs, mid + 1, r, pos, t);
		sum[x] = (sum[ls] + sum[rs]) % mod;
	}

	void modify(int pos, int t) {
		modify(1, 1, n, pos, t);
	}

	void mul(int t) {
		sum[1] = 1ll * sum[1] * t % mod;
		tag[1] = 1ll * tag[1] * t % mod;
	}

	int query(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return sum[x];
		}
		int mid = l + r >> 1, res = 0;
		pushdown(x);
		if (mid >= L) res = (res + query(ls, l, mid, L, R)) % mod;
		if (mid + 1 <= R) res = (res + query(rs, mid + 1, r, L, R)) % mod;
		return res;
	}

	int query(int l, int r) {
		return query(1, 1, n, l, r);
	}
};

int main() {
	int n, m, c, ic;
	std::cin >> n >> m >> c;
	c = (c + mod) % mod;
	ic = qpow(c);
	std::vector<std::vector<int> > edge(n + 1);
	for (int u = 2; u <= n; u++) {
		int v;
		std::cin >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	std::vector<std::vector<int> > qry(n + 1);
	std::vector<std::vector<PII> > mdf(n + 1);
	for (int i = 1; i <= m; i++) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int u, x;
			std::cin >> u >> x;
			x = (x + mod - 1) % (mod - 1);
			mdf[u].push_back({qpow(c, x), i});
		} else {
			int u;
			std::cin >> u;
			qry[u].push_back(i);
		}
	}
	SEG seg(m);
	std::vector<int> ans(m + 1, -1);
	std::function<void(int, int)> dfs = [&](int u, int last) -> void {
		// std::cout << "test:" << u << endl;
		for (auto [y, x] : mdf[u]) {
			// std::cout << x << ' ' << y << endl;
			seg.modify(x, y);
		}
		for (auto Q : qry[u]) {
			// std::cout << Q << endl;
			ans[Q] = seg.query(1, Q);
		}
		// for (int i = 1; i <= m; i++) {
		// 	std::cout << seg.query(1, i) << ' ';
		// }
		// std::cout << endl;
		for (auto v : edge[u]) {
			if (v == last) continue;
			seg.mul(c);
			dfs(v, u);
			seg.mul(ic);
		}
		for (auto [y, x] : mdf[u]) {
			seg.modify(x, -y);
		}
	};
	dfs(1, 1);
	for (int i = 1; i <= m; i++) {
		if (ans[i] == -1) continue;
		std::cout << ans[i] << endl;
	}
	return 0;
}