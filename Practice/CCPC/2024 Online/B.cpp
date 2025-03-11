#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

int main() {
	int n;
	std::cin >> n;
	std::vector<int64> a(n + 1), mul(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	mul[0] = 1;
	for (int i = 1; i <= n; i++) {
		mul[i] = mul[i - 1] * i % mod;
	}
	std::sort(a.begin() + 1, a.end());
	std::vector<int64> b(n + 1, a[1]);
	b[0] = 0;
	if (a == b) {
		std::cout << 0 << ' ' << mul[n] << '\n';
		return 0;
	}
	int64 ans = 0, cnt = 2, p = 1;
	for (int i = 1; i <= n; i++) {
		if (i && a[i] != a[i - 1]) {
			cnt = cnt * mul[p] % mod;
			p = 1;
		} else {
			p++;
		}
		for (int j = 1; j < i; j++) {
			ans += a[i] - a[j];
		}
	}
	cnt = cnt * mul[p] % mod;
	std::cout << ans << ' ' << cnt << '\n';
}