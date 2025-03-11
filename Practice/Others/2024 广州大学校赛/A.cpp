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
	std::vector<std::vector<std::string>> s(3, std::vector<std::string>(5));

	s[0][0] = "###";
	s[0][1] = "#.#";
	s[0][2] = "###";
	s[0][3] = "#.#";
	s[0][4] = "###";

	s[1][0] = "###";
	s[1][1] = "..#";
	s[1][2] = ".##";
	s[1][3] = "..#";
	s[1][4] = "..#";

	s[2][0] = "###";
	s[2][1] = "#.#";
	s[2][2] = "###";
	s[2][3] = "#..";
	s[2][4] = "#..";

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> map(n);
	for (int i = 0; i < n; i++) {
		std::cin >> map[i];
	}
	std::vector<int> ans(3);
	for (int i = n - 1; i - 4 >= 0; i--) {
		for (int j = 0; j + 2 < m; j++) {
			for (int k = 0; k < 3; k++) {
				bool flag = 0;
				for (int x = 4; x >= 0; x--) {
					for (int y = 0; y <= 2; y++) {
						if (map[i - 4 + x][j + y] != s[k][x][y]){
							flag = 1;
						}
					}
				}
				if (!flag) {
					ans[k]++;
					for (int x = 4; x >= 0; x--) {
						for (int y = 0; y <= 2; y++) {
							map[i - 4 + x][j + y] = '.';
						}
					}
					break;
				}
			}
		}
	}
	std::cout << ans[2] << ' ' << ans[1] << ' ' << ans[0] << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}