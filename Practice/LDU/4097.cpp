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
		if (n == m) m--;
		std::vector<std::vector<int>> a(m, std::vector<int>(n));
		std::vector<std::vector<int>> visx(m, std::vector<int>(n));
		std::vector<std::vector<int>> visy(n, std::vector<int>(n));
		std::vector<int64> mul(n + 1);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			mul[i] = mul[i - 1] * i;
		}
		int64 res = 0;
		auto dfs = [&](auto self, int x, int y) -> void {
			if (y == n) {
				x++;
				y = 1;
			}
			if (x == m) {
				res++;
				return;
			}
			int s = 0, t = n;
			for (int i = s; i < t; i++) {
				if (visx[x][i] || visy[y][i]) continue;
				a[x][y] = i;
				visx[x][i] = 1;
				visy[y][i] = 1;
				self(self, x, y + 1);
				visx[x][i] = 0;
				visy[y][i] = 0;
			}
		};
		for (int i = 0; i < n; i++) {
			a[0][i] = i;
			visy[i][i] = 1;
		}
		for (int i = 0; i < m; i++) {
			a[i][0] = i;
			visx[i][i] = 1;
		}
		dfs(dfs, 1, 1);
		std::cout << res * mul[n] * (mul[n - 1] / mul[n - m]) << endl;
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