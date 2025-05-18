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
	std::vector<int> l(n + 1), r(n + 1), w(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
		for (int j = 29; j >= 0; j--) {
			if ((l[i] >> j) == (r[i] >> j)) {
				w[i] = (l[i] >> j & r[i] >> j) << j;
			} else {
				break;
			}
		}
		r[i] -= w[i];
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << w[i] << " \n"[i == n];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << r[i] << " \n"[i == n];
	// }
	std::vector<std::vector<int>> Wbit(n + 1, std::vector<int>(30));
	std::vector<std::vector<int>> Rbit(n + 1, std::vector<int>(30));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 30; j++) {
			Wbit[i][j] = Wbit[i - 1][j] + (w[i] >> j & 1);
			Rbit[i][j] = Rbit[i - 1][j] + (r[i] >> j & 1);
		}
	}
	// for (int i = 0; i <= 3; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << Wbit[j][i] << " \n"[j == n];
	// 	}
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << Rbit[j][i] << " \n"[j == n];
	// 	}
	// }
	int m;
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int L, R, ans = 0;
		std::cin >> L >> R;
		for (int j = 29; j >= 0; j--) {
			if (Rbit[R][j] - Rbit[L - 1][j] > 1) {
				ans |= (1 << j + 1) - 1;
				break;
			}
			if (Wbit[R][j] - Wbit[L - 1][j] && Rbit[R][j] - Rbit[L - 1][j]) {
				ans |= (1 << j + 1) - 1;
				break;
			}
			if (Wbit[R][j] - Wbit[L - 1][j] || Rbit[R][j] - Rbit[L - 1][j]) {
				ans |= (1 << j);
			}
		}
		std::cout << ans << " \n"[i == m];
	}
	return 0;
}

int main() {
	Fast_IOS;
	int D = 1;
	std::cin >> D;
	while (D--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}