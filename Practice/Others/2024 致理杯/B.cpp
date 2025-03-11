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
	std::vector<std::string> s(6);
	std::vector<int> a(6);
	for (int i = 0; i < 6; i++) {
		std::cin >> s[i];
	}
	int ans = 0;
	auto dfs = [&](auto self, int x) -> void {
		if (x == 6) {
			// for (int i = 0; i < 6; i++) {
			// 	std::cout << a[i] << ' ';
			// }
			// std::cout << endl;
			int res = 0;
			for (int i = 0; i < n; i++) {
				std::vector<int> S(6);
				for (int j = 0; j < 6; j++) {
					S[j] = s[j][(i + a[j]) % n];
				}
				S[0] -= '0';
				S[2] -= '0';
				S[4] -= '0';
				S[5] -= '0';
				// for (int j = 0; j < 6; j++) {
				// 	std::cout << S[j] << ' ';
				// }
				// std::cout << endl;
				double b, c = S[4] * 10 + S[5];
				if (S[1] == '+') b = S[0] + S[2];
				if (S[1] == '-') b = S[0] - S[2];
				if (S[1] == '*') b = S[0] * S[2];
				if (S[1] == '/') {
					if (S[2] == 0) continue; 
					b = 1.0 * S[0] / S[2];
				}
				if (S[3] == '<') res += (b < c);
				if (S[3] == '=') res += (b == c);
				if (S[3] == '>') res += (b > c);
			}
			ans = std::max(ans, res);
			return;
		}
		for (int i = 0; i < n; i++) {
			a[x] = i;
			self(self, x + 1);
		}
	};
	dfs(dfs, 0);
	std::cout << ans << endl;
	return 0;
}

int main() {
	// Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int s = solve();
		if (s == 0) continue;
		if (s == YES) std::cout << "YES" << endl;
		if (s == NO) std::cout << "NO" << endl;
	}
	return 0;
}