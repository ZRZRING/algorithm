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
	int sum, ban;

	TAG() : sum(0), ban(0) {}
	TAG(int s, int b) : sum(s), ban(b) {}
};

class DATA {
public:
	int64 sum, ban;
	TAG tag;

	DATA() : sum(0), ban(0) {}
	DATA(int s, int b, TAG t) : sum(s), ban(b), tag(t) {}

	static DATA merge(DATA a, DATA b) {
		return DATA(MOD(!a.ban * a.sum + !b.ban * b.sum), 0, TAG());
	}

	void update(int l, int r, TAG t) {
		MOD(sum += t.sum);
		ban = t.ban;
		tag.sum += t.sum;
		tag.ban = t.ban;
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
		std::cout << l << ' ' << r << ' ' << t.ban << ' ' << t.sum << '\n';
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
		n++;
		SEG seg(n);
		std::vector<int> a(n + 1), b(m);
		for (int i = 2; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			std::cin >> b[i];
		}
		std::vector vis(n + 1, std::vector<int>(1));
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = a[i];
			vis[x].push_back(i);
			for (auto y : b) {
				int size = vis[x].size();
				if (y >= size) {
					continue;
				}
				seg.modify(vis[x][size - y - 1], vis[x][size - y] - 1, TAG(0, 1));
			}
			ans = seg.query(1, n).sum + 1;
			seg.modify(i, TAG(ans, 0));
			for (auto y : b) {
				int size = vis[x].size();
				if (y >= size) {
					continue;
				}
				seg.modify(vis[x][size - y - 1], vis[x][size - y] - 1, TAG(0, 0));
			}
			std::cout << ans << '\n';
		}
		std::cout << ans << '\n';
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