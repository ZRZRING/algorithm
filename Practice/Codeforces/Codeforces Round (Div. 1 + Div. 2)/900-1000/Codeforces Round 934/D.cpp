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
	int n, q;
	std::cin >> n >> q;
	std::string s, a;
	std::cin >> s;
	a.push_back('@');
	for (int i = 0; i < s.length(); i++) {
		a.push_back(s[i]);
		a.push_back('$');
	}
	a.pop_back();
	a.push_back('@');
	s = "@" + s;
	int m = a.length() - 2, r = 0, maxp = 0;
	std::vector<int> f(m + 1);
	for (int i = 1; i <= m; i++) {
		if (i < r) {
			f[i] = std::min(r - i, f[2 * maxp - i]);
		}
		while (a[i + f[i]] == a[i - f[i]]) f[i]++;
		if (i + f[i] > r) {
			r = i + f[i];
			maxp = i;
		}
	}
	// for (int i = 1; i <= m; i++) {
	// 	std::cout << f[i] << ' ';
	// }
	// std::cout << endl;
	std::vector<int64> odd(n + 1), even(n + 1), t1(n + 1), t2(n + 1);
	for (int i = 2; i <= n; i++) {
		t1[i] = t1[i - 1] + (s[i] != s[i - 1]);
		t2[i] = t2[i - 2] + (s[i] != s[i - 2]);
		odd[i] = odd[i - 1] + (i % 2 == 1) * i;
		even[i] = even[i - 1] + (i % 2 == 0) * i;
	}
	while (q--) {
		int l, r, len;
		std::cin >> l >> r;
		len = r - l + 1;
		int64 ans = len * (len + 1ll) / 2ll - 1ll;
		if (f[l + r - 1] >= len) {
			ans -= len;
		}
		if (t1[r] == t1[l]) {
			ans -= even[len - 1];
		}
		if (len % 2 == 1) {
			if (t2[r] == t2[l] && t2[r - 1] == t2[l + 1]) {
				ans -= odd[len - 1];
			}
		} else {
			if (t2[r] == t2[l + 1] && t2[r - 1] == t2[l]) {
				ans -= odd[len - 1];
			}
		}
		std::cout << ans << endl;
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