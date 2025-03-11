#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

template<class T>
T MOD(T &x, int64 p = mod) {
	return x = (x % p + p) % p;
}

template<class T>
T MOD(T &&x, int64 p = mod) {
	return x = (x % p + p) % p;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	s = " " + s;
	#define A2 std::array<int, 2>
	std::vector<int> a(2 * n + 1);
	std::vector cnt(2 * n + 1, std::vector<int>(26));
	std::vector cnt0(26, std::vector<int>());
	std::vector cnt1(26, std::vector<int>());
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		for (int j = 0; j < 26; j++) {
			if (j == s[i] - 'A') {
				cnt[i][j] = cnt[i - 1][j] + 1;
				if (cnt[i][j] & 1) {
					cnt1[j].push_back(i);
				} else {
					cnt0[j].push_back(i);
				}
			} else {
				cnt[i][j] = cnt[i - 1][j];
			}
		}
	}
	for (int i = n + 1; i <= n + n; i++) {
		a[i] = a[i - n];
		for (int j = 0; j < 26; j++) {
			if (j == s[i - n] - 'A') {
				cnt[i][j] = cnt[i - 1][j] + 1;
				if (cnt[i][j] & 1) {
					cnt1[j].push_back(i);
				} else {
					cnt0[j].push_back(i);
				}
			} else {
				cnt[i][j] = cnt[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int x, y;
			std::cin >> x >> y;
			a[x] = y;
			a[x + n] = y;
		} else {
			int l, r;
			int64 ans = 0;
			std::cin >> l >> r;
			if (l > r) {
				int t = l;
				l = r;
				r = t + n;
			}
			// std::cout << l << ' ' << r << '\n';
			for (int j = 0; j < 26; j++) {
				int t = cnt[r][j] - cnt[l - 1][j];
				if (t % 2 == 0) continue;
				int d = 0;
				if (cnt0[j].back() >= r) d = std::max(d, *(std::upper_bound(cnt[j].begin(), cnt[j].end(), r) - 1));
				if (cnt1[j].back() >= r) d = std::max(d, *(std::upper_bound(cnt[j].begin(), cnt[j].end(), r) - 1));
				// std::cout << d << '\n';
				if (d >= l) ans += a[d];
			}
			std::cout << ans << '\n';
		}
	}
}

int main() {
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}