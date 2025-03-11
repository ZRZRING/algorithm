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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::set<A2> e;
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			e.insert({u, v});
		}
		std::vector<int> to(n + 1);
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			to[i] = to[i - 1];
			for (int j = i - 1; j >= std::max(to[i - 1], 1); j--) {
				bool flag = 0;
				for (int k = j; k < i; k++) {
					if (!e.count({k, i})) {
						flag = 1;
						break;
					}
				}
				if (flag) {
					to[i] = j + 1;
					break;
				}
			}
			// std::cout << to[i] << ' ' << i << endl;
			ans += i - to[i] + 1;
		}
		std::cout << ans << endl;
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