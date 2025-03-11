#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

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

	int64 qpow(int64 a, int64 x = mod - 2) {
		a %= mod;
		x %= mod - 1;
		int64 res = 1;
		while (x) {
			if (x & 1) res = res * a % mod;
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	void solve() {
		int n, cnt1 = 0;
		std::cin >> n;
		std::vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		std::map<int, std::vector<std::array<int64, 2>>> a;
		for (int i = 1; i <= n; i++) {
			int64 x, val = 1, t = 0;
			std::cin >> x;
			for (int j = 0; j < 11; j++) {
				while (x % prime[j] == 0) {
					x /= prime[j];
					if (getbit(t, j)) {
						MOD(val *= prime[j]);
					}
					t ^= 1 << j;
				}
			}
			if (x > 1) t ^= 1 << 11;
			a[x].push_back({t, val});
		}
		int64 ans = 1, c = 0;
		std::vector<std::vector<int64>> f(2, std::vector<int64>(1 << 12));
		f[0][0] = 1;
		for (auto [S, s] : a) {
			for (int i = 1 << 11; i < 1 << 12; i++) {
				f[c][i] = 0;
			}
			for (auto [x, t] : s) {
				c ^= 1;
				f[c] = f[c ^ 1];
				for (int i = 0; i < 1 << 12; i++) {
					int64 val = getbit(i, 11) ? S : 1ll;
					for (int j = 0; j < 11; j++) {
						if (getbit(i, j) && getbit(x, j)) {
							MOD(val *= prime[j]);
						}
					}
					MOD(f[c][i] += f[c ^ 1][i ^ x] * t % mod * val % mod);
				}
				// std::cout << f[c][0] << endl;
			}
		}
		std::cout << f[c][0] - 1 << endl;
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}