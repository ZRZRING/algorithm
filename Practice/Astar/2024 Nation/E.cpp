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
	int l = 0, r = 1e9;
	auto check = [&](int d) -> bool {
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
		return cnt <= k;
	};
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << r << '\n';
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
	std::vector pre(n + 1, std::vector<int>(21));
	std::map<int, int> s;
	for (int i = 1, j = 0; i <= n; i++) {
		s[a[i]]++;
		while (s.rbegin()->first - s.begin()->first > d) {
			j++;
			s[a[j]]--;
			if (s[a[j]] == 0) s.erase(a[j]);
		}
		pre[i][0] = j;
	}
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i <= n; i++) {
			pre[i][j] = pre[pre[i][j - 1]][j - 1];
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= 3; j++) {
	// 		std::cout << pre[i][j] << ' ';
	// 	}
	// 	std::cout << '\n';
	// }
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int t = k, r = i, l = i;
		for (int j = 20; j >= 0; j--) {
			if (t < 1 << j) continue;
			t -= 1 << j;
			l = pre[l][j];
		}
		// std::cout << l << ' ' << r << '\n';
		ans = std::max(ans, r - l);
	}
	std::cout << ans << '\n';
}

int main() {
	int T = 1;
	// std::cin >> T;
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