#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N = 5000;

	std::vector<std::vector<int64>> C;

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
		C.resize(N + 1);
		for (int i = 0; i <= N; i++) {
			C[i].resize(N + 1);
		}
		C[0][0] = 1;
		for (int i = 1; i <= N; i++) {
			C[i][0] = 1;
			for (int j = 1; j < i; j++) {
				MOD(C[i][j] = C[i - 1][j - 1] + C[i - 1][j]);
			}
			C[i][i] = 1;
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			MOD(ans += C[n][i] * qpow(qpow(2, i) - 1 + mod, m - 1) % mod * qpow(2, (n - i) * (m - 1)) % mod);
		}
		std::cout << ans << endl;
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