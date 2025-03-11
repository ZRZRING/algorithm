#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		b[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		c[a[i]] = b[i];
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << c[i] << ' ';
	// }
	// std::cout << endl;
	int p = 1, cnt = 0;
	for (int s = n; s >= 1; s--) {
		for (int i = 1; i <= s - 1; i++) {
			if (c[p] == s) {
				std::cout << 2;
				c.push_back(c[p + 1]);
				c[p + 1] = c[p];
				p++;
			} else {
				std::cout << 1;
				c.push_back(c[p]);
				p++;
			}
		}
		for (int i = s; i <= n; i++) {
			std::cout << 1;
			c.push_back(c[p]);
			p++;
		}
	}
	std::cout << endl;
	// for (auto x : c) {
	// 	std::cout << x << ' ';
	// }
	// std::cout << endl;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}