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
		int n, m;
		std::cin >> n >> m;
		std::vector<int64> a(n + m + 2), b(n + m + 2);
		for (int i = 1; i <= n + m + 1; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n + m + 1; i++) {
			std::cin >> b[i];
		}
		if (n == 0) {
			int64 sum = 0;
			for (int i = 1; i <= n + m + 1; i++) {
				sum += b[i];
			}
			for (int i = 1; i <= n + m + 1; i++) {
				std::cout << sum - b[i] << " \n"[i == n + m + 1];
			}
			return;
		}
		if (m == 0) {
			int64 sum = 0;
			for (int i = 1; i <= n + m + 1; i++) {
				sum += a[i];
			}
			for (int i = 1; i <= n + m + 1; i++) {
				std::cout << sum - a[i] << " \n"[i == n + m + 1];
			}
			return;
		}
		int64 flag = 0, A = 0, B = 0, res = 0;
		std::vector<int64> ans(n + m + 2), vis(n + m + 2);
		for (int i = 1; i <= n + m + 1; i++) {
			if (a[i] > b[i]) A++; else B++;
			if (!flag && A > n) {
				flag = 1;
				for (int j = 1; j < i; j++) {
					ans[j] += (a[j] > b[j] ? a[i] : b[i]);
				}
				for (int j = i + 1; j <= n + m + 1; j++) {
					ans[j] += b[i];
				}
				continue;
			}
			if (!flag && B > m) {
				flag = 1;
				for (int j = 1; j < i; j++) {
					ans[j] += (a[j] > b[j] ? a[i] : b[i]);
				}
				for (int j = i + 1; j <= n + m + 1; j++) {
					ans[j] += a[i];
				}
				continue;
			}
			if (A > n) {
				res += b[i];
				vis[i] = b[i];
				continue;
			}
			if (B > m) {
				res += a[i];
				vis[i] = a[i];
				continue;
			}
			res += (a[i] > b[i] ? a[i] : b[i]);
			vis[i] = (a[i] > b[i] ? a[i] : b[i]);
		}
		for (int i = 1; i <= n + m + 1; i++) {
			// std::cout << ans[i] << ' ' << vis[i] << endl;
			std::cout << res + ans[i] - vis[i] << " \n"[i == n + m + 1];
		}
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