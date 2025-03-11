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
		int64 n, k;
		std::cin >> n >> k;
		std::vector<PII> a(n + 1);
		for (int i = 1; i <= n; i++) {
			int64 c, w, to;
			std::cin >> c >> w >> to;
			a[i] = PII(to, c * w);
		}
		std::sort(a.begin() + 1, a.end(), [](PII a, PII b) {
			return a.first > b.first;
		});
		int64 now = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (now) {
				int64 t = std::min(now, a[i].second); 
				now -= t;
				a[i].second -= t;
			}
			int64 t = a[i].second / k;
			ans += t * a[i].first;
			a[i].second -= t * k;
			if (a[i].second) {
				ans += a[i].first;
				now = k - a[i].second;
			}
		}
		std::cout << ans << endl;
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