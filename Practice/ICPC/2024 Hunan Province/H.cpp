#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T QMOD(T& x, int64 p = mod) {
	while (x < 0) x += p;
	while (x >= p) x -= p;
	return x;
}
template <class T>
T QMOD(T&& x, int64 p = mod) {
	while (x < 0) x += p;
	while (x >= p) x -= p;
	return x;
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::string s;
		std::cin >> s;
		int len = s.length();
		s = " " + s;
		std::vector<int> fail(len + 1);
		fail[0] = -1;
		for (int i = 2, j = 0; i <= len; i++) {
			while (j && s[i] != s[j + 1]) j = fail[j];
			if (s[i] == s[j + 1]) j++;
			fail[i] = j;
		}
		std::vector f(n + 1, std::vector(m + 2, std::vector(len, int64(0))));
		f[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k < len; k++) {
					for (char c = 'a'; c <= 'z'; c++) {
						// std::cout << i << ' ' << j << ' ' << k << ' ' << c << '\n';
						bool flag = 0;
						for (int x = k; ~x; x = fail[x]) {
							if (c == s[x + 1]) {
								if (x == len - 1) {
									QMOD(f[i + 1][j + 1][0] += f[i][j][k]);
								} else {
									QMOD(f[i + 1][j][x + 1] += f[i][j][k]);
								}
								flag = 1;
								break;
							}
						}
						if (!flag) {
							QMOD(f[i + 1][j][0] += f[i][j][k]);
						}
 					}
				}
			}
		}
		int64 ans = 0;
		for (int i = 0; i < len; i++) {
			QMOD(ans += f[n][m][i]);
		}
		std::cout << ans << '\n';
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}