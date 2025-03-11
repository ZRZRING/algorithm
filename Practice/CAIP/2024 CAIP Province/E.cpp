#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

struct NODE {
	int t, d, p;
};

void solve() {
	int n, m = 0;
	std::cin >> n;
	std::vector<NODE> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].t >> a[i].d >> a[i].p;
		m = std::max(m, a[i].d);
	}
	std::sort(a.begin() + 1, a.end(), [](NODE a, NODE b) {
		return a.d < b.d;
	});
	std::vector<int> f(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = a[i].d; j >= a[i].t; j--) {
			f[j] = std::max(f[j], f[j - a[i].t] + a[i].p);
		}
	}
	int ans = 0;
	for (int j = 0; j <= m; j++) {
		ans = std::max(ans, f[j]);
	}
	std::cout << ans << endl;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}
