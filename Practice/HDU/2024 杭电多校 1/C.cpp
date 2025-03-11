#include <bits/stdc++.h>

using int64 = unsigned long long;

#define endl '\n'
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

class BIT {
public:
	int n;

	std::vector<int64> sum;
	
	BIT(int n) : n(n) {
		sum.resize(n + 1);
	}

	void add(int x, int64 t) {
		for (int i = x; i <= n; i += lowbit(i)) {
			sum[i] += t;
		}
	}

	int64 query(int x) {
		int64 res = 0;
		for (int i = x; i; i -= lowbit(i)) {
			res += sum[i];
		}
		return res;
	}

	int64 query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m = 1e6;
		std::cin >> n;
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int cnt = 0;
		std::vector<int64> f(n + 1);
		std::vector<int> son(n + 1), size(n + 1);
		std::vector<int> L(n + 1), R(n + 1), id(n + 1);
		auto dfs0 = [&](auto self, int u, int last) -> void {
			L[u] = ++cnt;
			id[cnt] = u;
			size[u] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				if (size[v] > size[son[u]]) {
					son[u] = v;
				}
				size[u] += size[v];
			}
			R[u] = cnt;
		};
		dfs0(dfs0, 1, 1);
		BIT bit(m), bit2(m);
		int64 sum = 0;
		auto dfs = [&](auto self, int u, int last, int kp) -> void {
			for (auto v : e[u]) {
				if (v == last || v == son[u]) continue;
				self(self, v, u, 0);
			}
			if (son[u]) {
				self(self, son[u], u, 1);
				f[u] += f[son[u]];
			}
			for (auto v : e[u]) {
				if (v == last || v == son[u]) continue;
				for (int i = L[v]; i <= R[v]; i++) {
					int64 x = a[id[i]];
					f[u] += bit.query(1, x) * x * x + bit2.query(x + 1, m) - sum * x;
					sum += x;
					bit.add(x, 1);
					bit2.add(x, x * x);
				}
			}
			int64 x = a[u];
			f[u] += bit.query(1, x) * x * x + bit2.query(x + 1, m) - sum * x;
			sum += x;
			bit.add(x, 1);
			bit2.add(x, x * x);
			if (kp == 0) {
				for (int i = L[u]; i <= R[u]; i++) {
					int64 x = a[id[i]];
					sum -= x;
					bit.add(x, -1);
					bit2.add(x, -x * x);
				}
			}
		};
		dfs(dfs, 1, 1, 1);
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			// std::cout << f[i] * 2 << endl;
			ans ^= f[i] * 2;
		}
		std::cout << ans << endl;
	}
};

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}