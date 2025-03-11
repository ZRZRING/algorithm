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
		int n;
		std::cin >> n;
		#define A4 std::array<int, 4>
		std::vector<A4> a(n + 1);
		std::vector<int> X(1), Y(1);
		for (int i = 1; i <= n; i++) {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			a[i] = {x1, y1, x2, y2};
			X.push_back(x1);
			X.push_back(x2);
			Y.push_back(y1);
			Y.push_back(y2);
		}
		std::sort(X.begin(), X.end());
		std::sort(Y.begin(), Y.end());
		int h, w;
		h = std::unique(X.begin(), X.end()) - X.begin();
		w = std::unique(Y.begin(), Y.end()) - Y.begin();
		X.resize(h);
		Y.resize(w);
		std::vector<std::vector<int>> vis(h + 1, std::vector<int>(w + 1));
		for (int i = 1; i <= n; i++) {
			int x1, y1, x2, y2;
			x1 = std::lower_bound(X.begin(), X.end(), a[i][0]) - X.begin();
			y1 = std::lower_bound(Y.begin(), Y.end(), a[i][1]) - Y.begin();
			x2 = std::lower_bound(X.begin(), X.end(), a[i][2]) - X.begin();
			y2 = std::lower_bound(Y.begin(), Y.end(), a[i][3]) - Y.begin();
			// std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
			vis[x1][y1]++;
			vis[x1][y2]--;
			vis[x2][y1]--;
			vis[x2][y2]++;
		}
		std::vector<int64> g(n + 1);
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++) {
				vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
				// std::cout << i << ' ' << j << ' ' << vis[i][j] << endl;
				MOD(g[vis[i][j]] += 1ll * MOD(X[i + 1] - X[i]) * MOD(Y[j + 1] - Y[j]) % mod);
			}
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << g[i] << endl;
		// }
		std::vector<int64> mul(n + 1), inv(n + 1);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			mul[i] = mul[i - 1] * i % mod;
		}
		inv[n] = qpow(mul[n]);
		for (int i = n - 1; i >= 0; i--) {
			inv[i] = inv[i + 1] * (i + 1) % mod;
		}
		auto C = [&](int n, int m) -> int64 {
			if (n < m) return 0;
			return mul[n] * inv[m] % mod * inv[n - m] % mod;
		};
		std::vector<int64> ans(n + 1);
		for (int k = 1; k <= n; k++) {
			int64 Cnk = C(n, k), iCnk = qpow(Cnk);
			for (int i = 1; i <= n; i++) {
				MOD(ans[k] += MOD(Cnk - C(n - i, k)) * g[i] % mod);
			}
			MOD(ans[k] *= iCnk);
		}
		for (int i = 1; i <= n; i++) {
			std::cout << ans[i] << endl;
		}
	}
};

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}