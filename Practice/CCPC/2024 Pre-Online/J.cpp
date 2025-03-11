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
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<A2> ans;
		for (int k = 59; k >= 0; k--) {
			std::vector<int> bit;
			for (int i = 1; i <= n; i++) {
				if ((a[i] >> k & 1) == 1) {
					bit.push_back(i);
				}
			}
			if (bit.size() > 2) {
				std::cout << -1 << '\n';
				return;
			}
			if (bit.empty()) continue;
			int64 t = a[bit[0]] - (a[bit[0]] ^ a[bit[1]]);
			ans.push_back({bit[0], t});
			a[bit[0]] -= t;
			a[bit[1]] = 0;
		}
		std::cout << ans.size() << '\n';
		for (auto [x, y] : ans) {
			std::cout << x << ' ' << y << '\n';
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