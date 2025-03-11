#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long
#define A4 std::array<int64, 4>

const int64 mod = 998244353;

void solve() {
	int n;
	std::cin >> n;
	int64 sum = 0;
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::sort(a.begin() + 1, a.end());
	if (n == 1) {
		std::cout << a[1] << endl;
		return;
	}
	if (n == 2) {
		std::cout << std::max({abs(a[2] - a[1]), abs(a[1]), abs(a[2])}) << endl;
		return;
	}
	if (a[1] >= 0) {
		std::cout << sum + a[n] - a[1] - a[1] << endl;
		return;
	}
	if (a[n] <= 0) {
		std::cout << a[n] + a[n] - sum - a[1] << endl;
		return;
	}
	std::vector<int64> pre(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}
	int64 ans = std::max(suf[2] + a[n] - a[1], a[n] - pre[n - 1] - a[1]);
	for (int i = 2; i <= n - 2; i++) {
		ans = std::max(ans, suf[i + 1] + a[n] - pre[i] - a[1]);
	}
	std::cout << ans << endl;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}