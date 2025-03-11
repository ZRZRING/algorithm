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
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), ans(n + 1, 1e9);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (n == 1) {
		std::cout << -1 << endl;
		return 0;
	}
	for (auto z : {0, 1}) {
		// std::cout << z << endl;
		std::vector<int64> pre(n + 1);
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + a[i];
		}
		std::vector<int> last(n + 1);
		for (int i = 1; i <= n; i++) {
			int j = (z ? n - i + 1 : i);
			int l = 1, r = i - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (mid < last[i - 1] && pre[i - 1] - pre[mid - 1] > a[i]) {
					ans[j] = std::min(ans[j], i - mid);
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if (a[i - 1] > a[i]) ans[j] = std::min(ans[j], 1);
			last[i] = (a[i] == a[i - 1] ? last[i - 1] : i);
		}
		std::reverse(a.begin() + 1, a.end());
	}
	for (int i = 1; i <= n; i++) {
		std::cout << (ans[i] == 1e9 ? -1 : ans[i]) << " \n"[i == n];
	}
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