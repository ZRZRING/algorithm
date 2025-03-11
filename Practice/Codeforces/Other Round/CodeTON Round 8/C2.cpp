#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int solve() {
	int n, m, y;
	std::cin >> n >> m >> y;
	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	int64 ans = 0;
	std::vector<int> gap;
	for (int i = 2; i <= m; i++) {
		int t = a[i] - a[i - 1];
		if (t == 2) ans++;
		if (t >= 3 && t % 2 == 0) {
			gap.push_back(t / 2 - 1);
		}
	}
	int t = a[1] + n - a[m];
	if (t == 2) ans++;
	ans += m - 2;
	if (t >= 3 && t % 2 == 0) {
		gap.push_back(t / 2 - 1);
	}
	std::sort(gap.begin(), gap.end());
	std::reverse(gap.begin(), gap.end());
	while (y && !gap.empty()) {
		if (y >= gap.back()) ans++;
		ans += std::min(y, gap.back()) * 2;
		y -= std::min(y, gap.back());
		gap.pop_back();
	}
	ans += y * 2;
	std::cout << std::min(ans, n - 2ll) << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}