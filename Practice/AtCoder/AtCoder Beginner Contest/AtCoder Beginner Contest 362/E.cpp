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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n + 1);
		std::vector<std::map<PII, int64>> f(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				f[2][{j, a[j] - a[i]}] = 1;
			}
		}
		// f[i][{j, k}] 表示长度为 i 的等差数列，末项为 a[j]，差值为 k 的方案数
		for (int i = 3; i <= n; i++) {
			for (int j = i - 1; j <= n - 1; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (f[i - 1][{j, a[k] - a[j]}] == 0) {
						// 因为后面需要统计 size
						// 但这里一旦访问 f[i - 1][{j, a[k] - a[j]}]
						// 就会开辟这个空间，会被计入 size，所以需要删除
						f[i - 1].erase({j, a[k] - a[j]});
					} else {
						f[i][{k, a[k] - a[j]}] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			std::cout << f[i].size() << " \n"[i == n];
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