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

int n, k, d;

std::vector<int> a;

void solve1() {
	int ans = 1e9;
	for (int x = 0; x <= 1000; x++) {
		int cnt = 1, max = 1, min = 1e9;
		for (int i = 1; i <= n; i++) {
			max = std::max(max, a[i]);
			min = std::min(min, a[i]);
			if (max - min > x) {
				cnt++;
				max = a[i];
				min = a[i];
			}
		}
		if (cnt <= k) ans = std::min(x, ans);
	}
	std::cout << ans << '\n';
}

void solve2() {
	int cnt = 1, max = 1, min = 1e9;
	for (int i = 1; i <= n; i++) {
		max = std::max(max, a[i]);
		min = std::min(min, a[i]);
		if (max - min > d) {
			cnt++;
			max = a[i];
			min = a[i];
		}
	}
	std::cout << cnt << '\n';
}

void solve3() {
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		int cnt = 1, max = 1, min = 1e9;
		for (int r = l; r <= n; r++) {
			max = std::max(max, a[r]);
			min = std::min(min, a[r]);
			if (max - min > d) {
				cnt++;
				if (cnt == k + 1) {
					ans = std::max(ans, r - l);
					break;
				}
				max = a[r];
				min = a[r];
			}
		}
		if (cnt <= k) ans = std::max(ans, n - l + 1);
	}
	std::cout << ans << '\n';
}

int main() {
	int T = 1;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> k >> d;
		a.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		solve1();
		solve2();
		solve3();
	}
}