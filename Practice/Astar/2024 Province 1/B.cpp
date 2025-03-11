#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

const int64 mod = 998244353;

int64 qpow(int64 a, int x = mod - 2) {
	int64 res = 1;
	while (x) {
		if (x & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

int main() {
	int64 n, N = 1e7;
	std::cin >> n;
	std::vector<int64> vis(N + 1), p;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) {
			p.push_back(i);
		}
		for (int j = 0; j < p.size() && i * p[j] <= N; j++) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	int64 T = 1;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] > n) break;
		if (p[i] * p[i] > n) T = T * p[i] % mod;
		else {
			int64 t = 1;
			while (t * p[i] <= n) t *= p[i];
			T = T * t % mod;
		}
	}
	// std::cout << T << endl;
	int64 cnt = 0, ans = 0;
	std::vector<int64> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 1; i <= n; i++) {
		ans = (ans + cnt - T * (i - 1) % mod * inv[i] % mod + mod) % mod;
		cnt = (cnt + T * inv[i] % mod) % mod;
	}
	std::cout << ans << endl;
	return 0;
}