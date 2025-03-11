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
		int n, k, d;
		std::cin >> n >> k;
		d = (n % k == 0 ? k : n % k);
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int l = 1, r = 1e9;
		auto check = [&](int x) -> bool {
			std::vector<int> f(n + 1);
			for (int i = 1; i <= std::min(n, k); i++) {
				f[i] = f[i - 1] + (a[i] >= x);
			}
			for (int i = k + 1; i <= n; i++) {
				if (i % k == 1) {
					f[i] = std::max({f[i - k], int(a[i] >= x)});
				} else {
					f[i] = std::max({f[i - k], f[i - 1] + (a[i] >= x), f[i - k - 1] + (a[i] >= x)});
				}
			}
			// for (int i = 1; i <= n; i++) {
			// 	std::cout << f[i] << ' ';
			// }
			// std::cout << '\n';
			int ans = 0;
			for (int i = d; i <= n; i += k) {
				ans = std::max(ans, f[i]);
			}
			return ans >= d / 2 + 1;
		};
		// check(3);
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (check(mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		std::cout << r << '\n';
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