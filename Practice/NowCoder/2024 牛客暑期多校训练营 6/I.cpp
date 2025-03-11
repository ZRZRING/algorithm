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
		std::vector<std::vector<int64>> a(n + 1, std::vector<int64>(m + 2));
		std::vector<std::vector<int64>> f(n + 1, std::vector<int64>(m + 2));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			std::vector<int64> pre(m + 2), suf(m + 2);
			std::vector<int64> pre_f(m + 2), suf_f(m + 2);
			std::vector<int64> pre_max(m + 2), suf_max(m + 2);
			for (int j = 1; j <= m; j++) {
				pre_max[j] = std::max({pre_max[j - 1] + a[i][j - 1], 0ll});
			}
			for (int j = m; j >= 1; j--) {
				suf_max[j] = std::max({suf_max[j + 1] + a[i][j + 1], 0ll});
			}
			for (int j = 1; j <= m; j++) {
				pre[j] = pre[j - 1] + a[i][j];
			}
			for (int j = m; j >= 1; j--) {
				suf[j] = suf[j + 1] + a[i][j];
			}
			pre_f[0] = suf_f[m + 1] = -1e15;
			for (int j = 1; j <= m; j++) {
				pre_f[j] = std::max(pre_f[j - 1], f[i - 1][j] + suf[j] + pre_max[j]);
			}
			for (int j = m; j >= 1; j--) {
				suf_f[j] = std::max(suf_f[j + 1], f[i - 1][j] + pre[j] + suf_max[j]);
			}
			for (int j = 1; j <= m; j++) {
				f[i][j] = std::max(pre_f[j] - suf[j + 1] + suf_max[j], suf_f[j] - pre[j - 1] + pre_max[j]);
			}
		}
		int64 ans = -1e15;
		for (int i = 1; i <= m; i++) {
			ans = std::max(ans, f[n][i]);
		}
		std::cout << ans << '\n';
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