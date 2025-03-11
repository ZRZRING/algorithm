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

class TAG {
public:
	TAG() {}
	TAG() {}
};

class DATA {
public:
	TAG tag;

	DATA() {}
	DATA() {}

	static DATA merge(DATA a, DATA b) {
		
	}

	void update(int l, int r, TAG t) {
		
	}
};

class SEG {
public:
	#define ls x << 1
	#define rs x << 1 | 1

	int n;

	std::vector<DATA> data;

	SEG(int n) : n(n) {
		data.resize(n * 4);
	}

	void update(int x, int l, int r, TAG t) {
		data[x].update(l, r, t);
	}

	void pushup(int x) {
		data[x] = DATA::merge(data[ls], data[rs]);
	}

	void pushdown(int x, int l, int r, int mid) {
		update(ls, l, mid, data[x].tag);
		update(rs, mid + 1, r, data[x].tag);
		data[x].tag = TAG();
	}

	void modify(int x, int l, int r, int L, int R, TAG t) {
		if (L <= l && r <= R) {
			update(x, l, r, t);
			return;
		}
		int mid = l + r >> 1;
		pushdown(x, l, r, mid);
		if (mid >= L) {
			modify(ls, l, mid, L, R, t);
		}
		if (mid + 1 <= R) {
			modify(rs, mid + 1, r, L, R, t);
		}
		pushup(x);
	}

	void modify(int l, int r, TAG t) {
		modify(1, 1, n, l, r, t);
	}

	void modify(int pos, TAG t) {
		modify(1, 1, n, pos, pos, t);
	}

	DATA query(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return data[x];
		}
		int mid = l + r >> 1, res = 0;
		pushdown(x, l, r, mid);
		if (L <= mid && mid + 1 <= R) {
			return DATA::merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
		}
		if (L <= mid) {
			return query(ls, l, mid, L, R);
		}
		if (mid + 1 <= R) {
			return query(rs, mid + 1, r, L, R);
		}
	}

	DATA query(int l, int r) {
		return query(1, 1, n, l, r);
	}

	DATA query(int pos) {
		return query(1, 1, n, pos, pos);
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		SEG seg(n);
		for (int i = 1; i <= n; i++) {
			int64 t;
			std::cin >> t;
			seg.modify(i, i, t);
		}
		for (int i = 1; i <= m; i++) {
			int opt;
			std::cin >> opt;
			if (opt == 1) {
				int l, r;
				int64 t;
				std::cin >> l >> r >> t;
				seg.modify(l, r, TAG(t));
			} else {
				int l, r;
				std::cin >> l >> r;
				std::cout << seg.query(l, r).sum << '\n';
			}
		}
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}