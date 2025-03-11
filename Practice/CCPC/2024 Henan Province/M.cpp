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
		std::vector<int64> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		int l = 0, r = 1e9;
		auto check = [&](int k) -> bool {
			int64 L = -1e15, R = 1e15;
			for (int i = 1; i <= n; i++) {
				L = std::max(L, a[i] - b[i] * k);
				R = std::min(R, a[i] + b[i] * k);
			}
			return L <= R;
		};
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		std::cout << r << endl;
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