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
template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::array<int64, 5>> a(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 4; j++) {
				std::cin >> a[i][j];
			}
		}
		std::vector<int64> f(4 * n + 1, 1e15);
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 4 * i; j >= 0; j--) {
				for (int k = 0; k <= std::min(j, 4); k++) {
					f[j] = std::min(f[j], f[j - k] + a[i][k]);
				}
			}
		}
		std::cout << f[m] << endl;
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