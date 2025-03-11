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
		int n, m;
		std::cin >> n >> m;
		std::vector<int> cnt(m + 1);
		std::vector<std::string> model(m + 1);
		for (int i = 1; i <= m; i++) {
			std::cin >> model[i] >> cnt[i];
			model[i] = " " + model[i];
		}
		std::string res;
		res.resize(n + 1);
		res[0] = ' ';
		std::vector<std::string> ans;
		auto dfs = [&](auto self, int x) -> void {
			if (x == n + 1) {
				if (ans.size() == 2) return;
				int flag = 0;
				for (int i = 1; i <= m; i++) {
					std::vector<int> t0(n + 1), t1(n + 1);
					for (int j = 1; j <= n; j++) {	
						t0[j] = (res[j] - model[i][j] + 10) % 10;
						t1[j] = (model[i][j] - res[j] + 10) % 10;
					}
					if (n == 1) {
						if (std::min(t0[1], t1[1]) > cnt[i] || (cnt[i] - std::min(t0[1], t1[1])) % 2 == 1) {
							flag = 1;
							break;
						}
					} else if (res == model[i]) {
						if (cnt[i] == 1) {
							flag = 1;
							break;
						}
					} else {
						std::vector<int> f(n + 1, 1e9);
						f[0] = 0;
						for (int i = 1; i <= n; i++) {
							for (int j = 1; j <= i; j++) {
								int t = t0[j];
								for (int k = j + 1; k <= i; k++) {
									t += std::max(0, t0[k] - t0[k - 1]);
								}
								f[i] = std::min(f[i], f[j - 1] + t);
								t = t1[j];
								for (int k = j + 1; k <= i; k++) {
									t += std::max(0, t1[k] - t1[k - 1]);
								}
								f[i] = std::min(f[i], f[j - 1] + t);
							}
						}
						if (f[n] > cnt[i]) {
							flag = 1;
							break;
						}
					}
				}
				if (!flag) {
					// std::cout << res << '\n';
					ans.push_back(res);
				}
				return;
			}
			for (int i = 0; i < 10; i++) {
				res[x] = i + '0';
				self(self, x + 1);
			}
		};
		dfs(dfs, 1);
		if (ans.size() > 1) {
			return void(std::cout << "MANY\n");
		}
		if (ans.empty()) {
			return void(std::cout << "IMPOSSIBLE\n");
		}
		for (int i = 1; i <= n; i++) {
			std::cout << ans[0][i];
		}
		std::cout << '\n';
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