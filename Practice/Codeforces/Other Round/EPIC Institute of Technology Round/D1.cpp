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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, Q;
		std::cin >> n >> Q;
		for (int i = 2; i <= n; i++) {
			int x;
			std::cin >> x;
		}
		std::vector<int> fa(n + 1), ls(n + 1), rs(n + 1);
		std::queue<A2> q;
		q.push({1, n / 2});
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			if (y == 0) break;
			ls[x] = x + 1;
			rs[x] = x + y + 1;
			fa[ls[x]] = x;
			fa[rs[x]] = x;
			q.push({ls[x], y / 2});
			q.push({rs[x], y / 2});
		}
		std::vector<int> a(n + 1);
		int cnt = 0;
		auto check = [&](int x) -> bool {
			if (!x) return 0;
			if (fa[x] && a[fa[x]] != a[x] / 2) return 1;
			if (ls[x] && a[ls[x]] != a[x] * 2 && a[ls[x]] != a[x] * 2 + 1) return 1;
			if (rs[x] && a[rs[x]] != a[x] * 2 && a[rs[x]] != a[x] * 2 + 1) return 1;
			return 0;
		};
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (check(i)) cnt++;
		}
		// std::cout << cnt << '\n';
		while (Q--) {
			int x, y, t;
			std::cin >> x >> y;
			std::set<int> s;
			s.insert(x);
			s.insert(fa[x]);
			s.insert(ls[x]);
			s.insert(rs[x]);
			s.insert(y);
			s.insert(fa[y]);
			s.insert(ls[y]);
			s.insert(rs[y]);
			for (auto t : s) {
				if (check(t)) cnt--;
			}
			std::swap(a[x], a[y]);
			s.clear();
			s.insert(x);
			s.insert(fa[x]);
			s.insert(ls[x]);
			s.insert(rs[x]);
			s.insert(y);
			s.insert(fa[y]);
			s.insert(ls[y]);
			s.insert(rs[y]);
			for (auto t : s) {
				if (check(t)) cnt++;
			}
			if (cnt == 0) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
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