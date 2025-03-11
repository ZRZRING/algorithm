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
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1), b(n + 2);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
			ans += abs(a[i] - b[i]);
		}
		std::cin >> b[n + 1];
		int64 min = 2e9, flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= b[n + 1] && b[n + 1] <= b[i]) {
				flag = 0;
			}
			if (b[i] <= b[n + 1] && b[n + 1] <= a[i]) {
				flag = 0;
			}
			min = std::min({min, abs(a[i] - b[n + 1]), abs(b[i] - b[n + 1])});
		}
		std::cout << ans + 1ll + flag * min << endl;
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