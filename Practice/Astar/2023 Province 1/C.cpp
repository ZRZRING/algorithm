#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct WORK {
	int N;

	WORK() {}

	void solve() {
		int64 n, m;
		std::cin >> n >> m;
		std::vector<int64> s(n + 1), v(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> s[i] >> v[i];
		}
		int64 l = 1, r = 5e9;
		auto check = [&](int64 x) -> int64 {
			int64 sum = 0, max = 0;
			for (int i = 1; i <= n; i++) {
				int64 t = (x - s[i]) * v[i];
				max = std::max(max, t);
				sum += std::max(0ll, t);
			}
			return sum - max >= m;
		};
		while (l < r) {
			int64 mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (r == 5e9) {
			std::cout << -1 << endl;
		} else {
			std::cout << r << endl;
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