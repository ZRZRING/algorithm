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
	int n, m;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<PII> a(n + 1);
		for (int i = 1; i <= n; i++) {
			int x, t;
			std::cin >> x >> t;
			a[i] = {x, t};
		}
		std::sort(a.begin(), a.end());
		int64 sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i].second;
			if (sum > a[i].first * m) {
				return (void)(std::cout << "No" << endl);
			}
		}
		return (void)(std::cout << "Yes" << endl);
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