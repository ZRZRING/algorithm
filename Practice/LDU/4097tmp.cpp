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
		int m, n;
		std::cin >> m >> n;
		std::vector<std::vector<int>> a(m, std::vector<int>(n));
		std::vector<std::vector<int>> visx(n, std::vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = (j + i) % n;
				// std::cout << a[i][j] << " \n"[j == n - 1];
			}
		}
		std::vector<int64> f(m), visy(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[0] *= i;
		}
		auto dfs = [&](auto self, int y) -> int64 {
			if (y == n) return 1;
			int64 res = 0;
			for (int i = 0; i < n; i++) {
				if (visy[i] || visx[y][i]) continue;
				visy[i] = 1;
				res += self(self, y + 1);
				visy[i] = 0;
			}
			return res;
		};
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visx[j][a[i - 1][j]] = 1;
			}
			f[i] = f[i - 1] * dfs(dfs, 0);
		}
		std::cout << f[m - 1] << endl;
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