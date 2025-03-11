#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
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
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			ans += a[i];
		}
		std::vector<int> vis(n + 1);
		int max = 0;
		for (int i = 1; i <= n; i++) {
			vis[a[i]]++;
			if (a[i] > max && vis[a[i]] >= 2) {
				max = a[i];
			}
			a[i] = max;
			ans += a[i];
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << a[i] << " \n"[i == n];
		// }
		vis.clear();
		vis.resize(n + 1);
		max = 0;
		for (int i = 1; i <= n; i++) {
			vis[a[i]]++;
			if (a[i] > max && vis[a[i]] >= 2) {
				max = a[i];
			}
			a[i] = max;
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << a[i] << " \n"[i == n];
		// }
		for (int i = 1; i <= n; i++) {
			ans += 1ll * a[i] * (n - i + 1);
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