#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}

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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1), to(n + 1), b(n + 1), fac(n + 1), ifac(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> to[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		fac[0] = 1;
		for (int i = 1; i <= n; i++) {
			fac[i] = fac[i - 1] * i % mod;
		}
		ifac[n] = qpow(fac[n]);
		for (int i = n - 1; i >= 0; i--) {
			ifac[i] = ifac[i + 1] * (i + 1) % mod;
		}
		std::vector<int64> dep(n + 1), vis(n + 1);
		auto dfs = [&](auto self, int u) -> void {
			vis[u] = 1;
			int v = to[u];
			if (a[u] < a[v]) {
				dep[u] = 1;
				return;
			}
			if (dep[v] == -1 || to[u] == u || a[u] >= a[v] + b[v]) {
				dep[u] = -1;
				return;
			}
			if (dep[v]) {
				dep[u] = dep[v] + 1;
				return;
			}
			if (vis[v]) {
				dep[u] = -1;
				return;
			}
			self(self, v);
			if (dep[v] == -1) dep[u] = -1;
			else dep[u] = dep[v] + 1;
		};
		for (int i = 1; i <= n; i++) {
			if (!dep[i]) dfs(dfs, i);
		}
		for (int i = 1; i <= n; i++) {
			if (dep[i] == -1) {
				std::cout << a[i] << " \n"[i == n];
			} else {
				std::cout << (a[i] + b[i] * ifac[dep[i]]) % mod << " \n"[i == n];
			}
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