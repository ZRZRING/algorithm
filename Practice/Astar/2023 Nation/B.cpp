#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define int64 long long
#define endl '\n'

const int mod = 1e9 + 7;

int qpow(int a, int x) {
	int res = 1;
	while (x) {
		if (x & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		x >>= 1;
	}
	return res;
}

int main() {
	int n, m, S, T;
	std::cin >> n >> m >> S >> T;
	std::vector<PII> mdf;
	mdf.push_back({S, n});
	mdf.push_back({T + 1, -n});
	for (int i = 1; i <= m; i++) {
		int x, l, r;
		std::cin >> x >> l >> r;
		mdf.push_back({std::max(l, S), -1});
		mdf.push_back({std::min(r + 1, T + 1), 1});
	}
	std::sort(mdf.begin(), mdf.end());
	int now = S, cnt = 0, ans = 1;
	for (auto [x, y] : mdf) {
		// std::cout << x << ' ' << y << endl;
		if (x != now) {
			// std::cout << cnt << ' ' << now << endl;
			ans = 1ll * ans * qpow(cnt, x - now) % mod;
		}
		now = x;
		cnt += y;
	}
	std::cout << ans << endl;
	return 0;
}
