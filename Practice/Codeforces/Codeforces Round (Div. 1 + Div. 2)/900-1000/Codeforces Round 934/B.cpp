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
	k = k * 2;
	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());
	std::vector<int> ans;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) {
			ans.push_back(a[i]);
			ans.push_back(a[i + 1]);
			a[i] = 0;
			a[i + 1] = 0;
			i++;
		}
		if (ans.size() == k) break;
	}
	for (int i = 1; i <= n; i++) {
		if (ans.size() == k) break;
		if (a[i] == 0) continue;
		ans.push_back(a[i]);
	}
	a = b;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) {
			ans.push_back(a[i]);
			ans.push_back(a[i + 1]);
			a[i] = 0;
			a[i + 1] = 0;
			i++;
		}
		if (ans.size() == k * 2) break;
	}
	for (int i = 1; i <= n; i++) {
		if (ans.size() == k * 2) break;
		if (a[i] == 0) continue;
		ans.push_back(a[i]);
	}
	for (int i = 0; i < k; i++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << endl;
	for (int i = k; i < 2 * k; i++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << endl;
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