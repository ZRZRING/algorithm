#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>
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
		int n, m;
		std::cin >> n >> m;
		std::vector<int> vis(n + 1);
		std::vector<std::vector<int>> a(2);
		std::vector<std::vector<int>> ans;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			if (x <= m) vis[x] = 1;
			a[x == 2].push_back(i);
		}
		if (n == 2 && m == 2) {
			if (a[1].size() == 2) {
				std::cout << 1 << '\n';
				std::cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
				return;
			}
		}
		int g = 0;
		for (int i = 2; i <= m; i++) {
			if (!vis[i]) {
				g = i;
				break;
			}
		}
		if (!g) {
			std::cout << -1 << '\n';
			return;
		}
		int p = n + 1;
		while (a[0].size() + a[1].size() >= g + 2) {
			if (a[0].size() >= 2) {
				std::vector<int> t(2);
				for (int i = 0; i < 2; i++) {
					t[i] = a[0].back();
					a[0].pop_back();
				}
				p++;
				a[0].push_back(p);
				p++;
				ans.push_back(t);
			} else {
				std::vector<int> t(3);
				for (int i = 0; i < 3; i++) {
					t[i] = a[1].back();
					a[1].pop_back();
				}
				p++;
				a[1].push_back(p);
				p++;
				ans.push_back(t);
			}
		}
		if (a[0].size() + a[1].size() == g + 1) {
			if (a[1].size() >= 2) {
				std::vector<int> t(2);
				for (int i = 0; i < 2; i++) {
					t[i] = a[1].back();
					a[1].pop_back();
				}
				a[1].push_back(p);
				p += 2;
				ans.push_back(t);
			} else {
				std::vector<int> t(2);
				for (int i = 0; i < 2; i++) {
					t[i] = a[0].back();
					a[0].pop_back();
				}
				p++;
				a[0].push_back(p);
				p++;
				ans.push_back(t);
			}
		}
		for (auto x : a[1]) {
			a[0].push_back(x);
		}
		std::vector<int> t(g);
		for (int i = 0; i < g; i++) {
			t[i] = a[0].back();
			a[0].pop_back();
		}
		p++;
		a[0].push_back(p);
		p++;
		ans.push_back(t);
		std::cout << ans.size() << '\n';
		for (auto x : ans) {
			std::cout << x.size() << ' ';
			for (auto y : x) {
				std::cout << y << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	for (int i = 1; i <= T; i++) {
		// std::cout << i << '\n';
		work.solve();
	}
	return 0;
}