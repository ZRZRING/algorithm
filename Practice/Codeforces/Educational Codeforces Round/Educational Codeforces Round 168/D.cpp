#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
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
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 2; i <= n; i++) {
			int x;
			std::cin >> x;
			e[x].push_back(i);
		}
		auto dfs = [&](auto self, int u) -> void {
			if (e[u].empty()) return;
			int min = 1e9;
			for (auto v : e[u]) {
				self(self, v);
				min = std::min(min, a[v]);
			}
			if (min > a[u])	a[u] = (a[u] + min) / 2;
			else a[u] = min;
		};
		int min = 1e9;
		for (auto v : e[1]) {
			dfs(dfs, v);
			min = std::min(min, a[v]);
		}
		std::cout << a[1] + min << endl;
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