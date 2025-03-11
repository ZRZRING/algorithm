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
	int n, k;
	std::cin >> n >> k;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			std::cout << i << " \n"[i == n];
		}
		std::cout << n << endl;
		for (int i = 1; i <= n; i++) {
			std::cout << i << " \n"[i == n];
		}
		return 0;
	}
	k = std::min(n, k);
	std::vector<int> a(n + 1);
	for (int i = 1; i + k - 1 <= n; i += k) {
		std::iota(a.begin() + i, a.begin() + i + k, i);
		std::reverse(a.begin() + i, a.begin() + i + (k + 1) / 2);
		std::reverse(a.begin() + i + (k + 1) / 2, a.begin() + i + k);
	}
	int t = n % k, c = n - t + 1;
	std::iota(a.begin() + c, a.begin() + c + t, c);
	std::reverse(a.begin() + c, a.begin() + c + (t + 1) / 2);
	std::reverse(a.begin() + c + (t + 1) / 2, a.begin() + c + t);
	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
	}
	std::cout << (n + k - 1) / k << endl;
	for (int i = 0; i < n; i++) {
		std::cout << i / k + 1 << " \n"[i == n - 1];
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