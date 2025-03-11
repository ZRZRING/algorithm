#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class SEG {
public:
	#define ls x << 1
	#define rs x << 1 | 1

	int n;

	std::vector<int64> cnt, min, tag;

	void build(int x, int l, int r) {
		if (l == r) {
			cnt[x] = 1;
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		cnt[x] = cnt[ls] + cnt[rs];
	}
	
	SEG(int n) : n(n) {
		cnt.resize(4 * n + 1);
		min.resize(4 * n + 1);
		tag.resize(4 * n + 1);
		build(1, 1, n);
	}

	A2 merge(A2 a, A2 b) {
		A2 c = {0, 0};
		c[0] = std::min(a[0], b[0]);
		if (c[0] == a[0]) {
			c[1] += a[1];
		}
		if (c[0] == b[0]) {
			c[1] += b[1];
		}
		return c;
	}

	void pushup(int x) {
		A2 t = merge({min[ls], cnt[ls]}, {min[rs], cnt[rs]});
		min[x] = t[0];
		cnt[x] = t[1];
	}

	void update(int x, int t) {
		tag[x] += t;
		min[x] += t;
	}

	void pushdown(int x) {
		update(ls, tag[x]);
		update(rs, tag[x]);
		tag[x] = 0;
	}

	void modify(int x, int l, int r, int L, int R, int t) {
		if (L > R || L < 1 || R > n) return;
		if (L <= l && r <= R) {
			update(x, t);
			return;
		}
		int mid = l + r >> 1;
		pushdown(x);
		if (mid >= L) {
			modify(ls, l, mid, L, R, t);
		}
		if (mid + 1 <= R) {
			modify(rs, mid + 1, r, L, R, t);
		}
		pushup(x);
	}

	A2 query(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return {min[x], cnt[x]};
		}
		int mid = l + r >> 1;
		A2 res = {(int64)1e9, 0};
		pushdown(x);
		if (L <= mid && mid + 1 <= R) {
			A2 t1 = query(ls, l, mid, L, R);
			A2 t2 = query(rs, mid + 1, r, L, R);
			res = merge(t1, t2);
		} else if (mid >= L) {
			res = query(ls, l, mid, L, R);
		} else if (mid + 1 <= R) {
			res = query(rs, mid + 1, r, L, R);
		}
		return res;
	}

	void modify(int l, int r, int t) {
		// std::cout << "M: " << l << ' ' << r << ' ' << t << '\n';
		modify(1, 1, n, l, r, t);
	}

	A2 query(int l, int r) {
		A2 t = query(1, 1, n, l, r);
		// std::cout << "Q: " << l << ' ' << r << ' ' << t[0] << ' ' << t[1] << '\n';
		return t;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::map<int, std::vector<int>> a;
		SEG seg(n);
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			if (a.find(x) == a.end()) {
				a[x].push_back(0);
			}
			if (a[x].size() <= m) {
				seg.modify(1, a[x].back(), -1);
			}
			if (a[x].size() == m + 1) {
				seg.modify(1, a[x][0], -1);
				seg.modify(a[x][1] + 1, a[x].back(), -1);
				a[x].erase(a[x].begin(), a[x].begin() + 1);
			}
			a[x].push_back(i);
			if (a[x].size() <= m) {
				seg.modify(1, a[x].back(), 1);
			}
			if (a[x].size() == m + 1) {
				seg.modify(1, a[x][0], 1);
				seg.modify(a[x][1] + 1, i, 1);
			}
			// std::cout << 'X' << x << ": ";
			// for (auto t : a[x]) {
			// 	std::cout << t << ' ';
			// }
			// std::cout << '\n';
			A2 t = seg.query(1, i);
			ans += (t[0] == 0) * t[1];
		}
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}