#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

int64 mod = 998244353;

template <typename T> T MOD(T &x) {return x = (x % mod + mod) % mod;}
template <typename T> T MOD(T &&x) {return x = (x % mod + mod) % mod;}
template <typename T> T lg(T x) {return (T)log10(x);}
template <typename T> T log(T x) {return (T)log2(x);}
template <typename T> T abs(T x) {return x < 0 ? -x : x;}
template <typename T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N = 5000;

	WORK() {}

	int64 qpow(int64 a, int64 x) {
		MOD(a);
		int64 res = 1;
		while (x) {
			if (x & 1) res = res * a % mod;
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	void solve() {
		int n, m;
		std::cin >> n >> m >> mod;
		std::vector<std::vector<int64>> C(N + 1, std::vector<int64>(N + 1));
		C[0][0] = 1;
		for (int i = 1; i <= N; i++) {
			C[i][0] = 1;
			for (int j = 1; j < i; j++) {
				MOD(C[i][j] = C[i - 1][j - 1] + C[i - 1][j]);
			}
			C[i][i] = 1;
		}
		std::vector<int64> pow2(n + 1);
		pow2[0] = 1;
		for (int i = 1; i <= n; i++) {
			pow2[i] = pow2[i - 1] * 2ll % mod;
		}
		int64 ans = 0;
		for (int i = 2; i <= n; i++) {
			MOD(ans += C[n][i] * qpow(pow2[i] - 1 + mod, m - 1) % mod * qpow(2, (n - i) * (m - 1)) % mod);
		}
		std::vector<int64> mul(n + 1);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			mul[i] = mul[i - 1] * i % mod;
		}
		std::vector<std::vector<int64>> f(n + 1, std::vector<int64>(m + 1));
		f[1][1] = 1;
		for (int i = 2; i <= m; i++) {
			f[1][i] = (f[1][i - 1] * 2 - 1 + mod) % mod;
		}
		for (int i = 2; i <= n; i++) {
			if (i <= m) f[i][i] = mul[i];
			for (int j = i + 1; j <= m - 1; j++) {
				f[i][j] = i * (f[i - 1][j - 1] + f[i][j - 1]) % mod;
			}
		}
		for (int i = 2; i <= n; i++) {
			int64 res = 0, c = MOD(pow2[i] - i - 1), c1 = qpow(2, (n - i) * (m - 1));
			std::vector<int64> powi(m + 1);
			powi[0] = 1;
			for (int j = 1; j <= m; j++) {
				powi[j] = powi[j - 1] * c % mod;
			}
			for (int j = i; j <= m - 1; j++) {
				MOD(res += f[i][j] * C[m - 1][j] % mod * powi[m - 1 - j] % mod * c1 % mod);
			}
			MOD(res *= C[n][i]);
			MOD(ans -= res);
		}
		std::cout << ans << endl;
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