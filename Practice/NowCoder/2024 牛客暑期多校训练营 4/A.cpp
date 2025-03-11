#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define A2 std::array<int, 2>
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

struct DSU {
	int n;

	std::vector<int> fa, h, max;

	DSU(int n) : n(n) {
		fa.resize(n + 1);
		h.resize(n + 1);
		max.resize(n + 1);
		std::iota(fa.begin(), fa.end(), 0);
	}

	int find(int x) {
		if (x == fa[x]) {
			return x;
		} else {
			int t = fa[x];
			fa[x] = find(fa[x]);
			h[x] += h[t];
			return fa[x];
		}
	}

	int merge(int x, int y) {
		int X = find(x);
		// std::cout << X << endl;
		if (x == y) return 0;
		fa[y] = X;
		max[X] = std::max(max[X], h[x] + max[y] + 1);
		h[y] = h[x] + 1;
		return 1;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		DSU dsu(n);
		for (int i = 1; i < n; i++) {
			int x, y, t;
			std::cin >> x >> y >> t;
			dsu.merge(x, y);
			std::cout << dsu.max[t] << " \n"[i == n - 1];
		}
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