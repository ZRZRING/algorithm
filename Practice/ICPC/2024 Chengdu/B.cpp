#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 1e9 + 7;

int N = 300, T = 1;

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

void init() {
	Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n, Q;
	std::cin >> n >> Q;
	std::string s;
	std::cin >> s;
	s = " " + s;
	std::vector f(3, std::vector(N + 1, std::vector(N + 1, std::vector(N + 1, int()))));
	std::vector g(3, std::vector(N + 1, std::vector(N + 1, std::vector(N + 1, int()))));
	int cnt = 0;
	if (s[1] == '?') {
		cnt++;
		f[0][1][0][0] = 1;
		f[1][0][1][0] = 1;
		f[2][0][0][1] = 1;
	}
	if (s[1] == 'a') {
		f[0][0][0][0] = 1;
	}
	if (s[1] == 'b') {
		f[1][0][0][0] = 1;
	}
	if (s[1] == 'c') {
		f[2][0][0][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (s[i] == '?') cnt++;
		for (int a = 0; a <= cnt; a++) {
			for (int b = 0; b <= cnt; b++) {
				int c = cnt - a - b;
				if (c < 0 || c > cnt) continue;
				if (s[i] == '?') {
					if (a) {
						QMOD(g[0][a][b][c] += QMOD(f[1][a - 1][b][c] + f[2][a - 1][b][c]));
					}
					if (b) {
						QMOD(g[1][a][b][c] += QMOD(f[0][a][b - 1][c] + f[2][a][b - 1][c]));
					}
					if (c) {
						QMOD(g[2][a][b][c] += QMOD(f[0][a][b][c - 1] + f[1][a][b][c - 1]));
					}
				}
				if (s[i] == 'a') {
					QMOD(g[0][a][b][c] += QMOD(f[1][a][b][c] + f[2][a][b][c]));
				}
				if (s[i] == 'b') {
					QMOD(g[1][a][b][c] += QMOD(f[0][a][b][c] + f[2][a][b][c]));
				}
				if (s[i] == 'c') {
					QMOD(g[2][a][b][c] += QMOD(f[0][a][b][c] + f[1][a][b][c]));
				}
			}
		}
		for (int p = 0; p < 3; p++) {
			for (int a = 0; a <= cnt; a++) {
				for (int b = 0; b <= cnt; b++) {
					for (int c = cnt - a - b - 1; c <= cnt - a - b; c++) {
						if (c < 0) continue;
						f[p][a][b][c] = g[p][a][b][c];
						g[p][a][b][c] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int sum = cnt + 1; sum <= 3 * cnt; sum++) {
			for (int a = 0; a <= cnt; a++) {
				for (int b = 0; b <= cnt; b++) {
					int c = sum - a - b;
					if (c < 0 || c > cnt) continue;
					// std::cout << a << ' ' << b << ' ' << c << '\n';
					if (a) {
						QMOD(f[i][a][b][c] += f[i][a - 1][b][c]);
					}
					if (b) {
						QMOD(f[i][a][b][c] += f[i][a][b - 1][c]);
					}
					if (c) {
						QMOD(f[i][a][b][c] += f[i][a][b][c - 1]);
					}
					if (a && b) {
						QMOD(f[i][a][b][c] -= f[i][a - 1][b - 1][c]);
					}
					if (b && c) {
						QMOD(f[i][a][b][c] -= f[i][a][b - 1][c - 1]);
					}
					if (c && a) {
						QMOD(f[i][a][b][c] -= f[i][a - 1][b][c - 1]);
					}
					if (a && b && c) {
						QMOD(f[i][a][b][c] += f[i][a - 1][b - 1][c - 1]);
					}
				}
			}
		}
	}
	while (Q--) {
		int x, y, z;
		std::cin >> x >> y >> z;
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			QMOD(ans += f[i][std::min(cnt, x)][std::min(cnt, y)][std::min(cnt, z)]);
		}
		std::cout << ans << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}