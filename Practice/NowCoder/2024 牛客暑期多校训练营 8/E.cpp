#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
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
	int N = 1e6;
	
	std::vector<int> vis, prime;

	WORK() {
		vis.resize(N + 1);
		for (int i = 2; i <= N; i++) {
			if (!vis[i]) {
				prime.push_back(i);
			}
			for (int j = 0; j < prime.size() && i * prime[j] <= N; j++) {
				vis[i * prime[j]] = 1;
				if (i % prime[j] == 0) break;
			}
		}
	}

	int S(int64 x) {
		int y = 0;
		while (x) {
			y += x % 10;
			x /= 10;
		}
		return y;
	}

	void solve() {
		int64 n;
		std::cin >> n;
		int64 B = 108;
		if (n <= B) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (S(i) == n % i) ans++;
			}
			std::cout << ans << '\n';
			return;
		}
		std::vector<int64> D;
		for (int i = 0; i <= B; i++) {
			D.push_back(n - i);
		}
		std::vector<std::vector<A2>> fac(B + 1);
		for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
			int64 p = prime[i];
			for (int d = n % p; d <= B; d += p) {
				int64 cnt = 0;
				while (D[d] % p == 0) {
					D[d] /= p;
					cnt++;
				}
				fac[d].push_back({p, cnt});
			}
		}
		for (int i = 0; i <= B; i++) {
			if (D[i] > 1) {
				fac[i].push_back({D[i], 1});
			}
		}
		// for (auto t : fac) {
		// 	for (auto [x, y] : t) {
		// 		std::cout << x << ' ' << y << '\n';
		// 	}
		// }
		int ans = 0;
		auto dfs = [&](auto self, int64 x, auto it, auto end, int t) -> void {
			if (it == end) {
				ans += (S(x) == t) && (x > t);
				return;
			}
			auto [p, k] = *it;
			for (int64 i = 0, P = 1; i <= k; i++, P *= p) {
				self(self, x * P, std::next(it), end, t);
			}
		};
		for (int i = 0; i <= B; i++) {
			dfs(dfs, 1, fac[i].begin(), fac[i].end(), i);
		}
		std::cout << ans << '\n';
	}
};

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}