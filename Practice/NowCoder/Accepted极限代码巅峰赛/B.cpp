#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353, inf = 1e15;

int N, T = 1;

void init() {
	Fast_IOS;
	std::cin >> T;
}

struct SEG {
	#define ls x << 1
	#define rs x << 1 | 1

	int n;

	std::vector<int64> data, max, tag;

	void update(int x, int64 t) {
		max[x] += t;
		tag[x] += t;
	}

	void pushdown(int x) {
		if (tag[x]) {
			update(ls, tag[x]);
			update(rs, tag[x]);
			tag[x] = 0;
		}
	}

	void pushup(int x) {
		max[x] = std::max(max[ls], max[rs]);
	}

	SEG(std::vector<int64> a) : data(a), n(a.size() - 1) {
		max.resize(4 * n + 1);
		tag.resize(4 * n + 1);
	}

	void add(int x, int l, int r, int L, int R, int64 t) {
		if (L <= l && r <= R) {
			update(x, t);
			return;
		}
		int mid = l + r >> 1;
		pushdown(x);
		if (mid >= L) {
			add(ls, l, mid, L, R, t);
		}
		if (mid + 1 <= R) {
			add(rs, mid + 1, r, L, R, t);
		}
		pushup(x);
	}

	void add(int l, int r, int64 t) {
		add(1, 1, n, l, r, t);
	}

	void modify(int x, int l, int r, int P, int64 t) {
		if (l == r) {
			max[x] = t;
			return;
		}
		int mid = l + r >> 1;
		pushdown(x);
		if (mid >= P) {
			modify(ls, l, mid, P, t);
		}
		if (mid + 1 <= P) {
			modify(rs, mid + 1, r, P, t);
		}
		pushup(x);
	}

	void modify(int pos, int64 t) {
		modify(1, 1, n, pos, t);
	}

	int64 query(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return max[x];
		}
		int mid = l + r >> 1;
		pushdown(x);
		int64 res = 0;
		if (mid >= L) {
			res = std::max(res, query(ls, l, mid, L, R));
		}
		if (mid + 1 <= R) {
			res = std::max(res, query(rs, mid + 1, r, L, R));
		}
		return res;
	}

	int64 query(int l, int r) {
		return query(1, 1, n, l, r);
	}
};

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int64> a(n + 1);
	int64 sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if (k == 1) {
		std::cout << sum << '\n';
		return;
	}
	SEG seg(a);
	std::vector<int64> f(n + 1), g(n + 1);
	for (int i = k; i <= n; i++) {
		g[i] = std::max(g[i - 1], f[i - k]);
		seg.modify(i, g[i]);
		seg.add(k, i, a[i]);
		f[i] = seg.query(1, n);
	}
	int64 ans = 0;
	for (int i = k; i <= n; i++) {
		ans = std::max(f[i], ans);
	}
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}