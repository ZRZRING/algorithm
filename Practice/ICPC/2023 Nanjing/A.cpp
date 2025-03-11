#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

const int gox[4] = {1, -1, 0, 0}, goy[4] = {0, 0, 1, -1};

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector s(n + 2, std::string());
	s[0].resize(m + 2);
	s[n + 1].resize(m + 2);
	for (int i = 0; i <= m + 1; i++) {
		s[0][i] = 'O';
		s[n + 1][i] = 'O';
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = "O" + s[i] + "O";
	}
	std::vector f(n + 1, std::vector(m + 1, std::vector(n + 1, std::vector(m + 1, int()))));
	std::vector vis(n + 1, std::vector(m + 1, std::vector(n + 1, std::vector(m + 1, int()))));
	std::queue<std::array<int, 4>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'O') continue;
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					// std::cout << i << ' ' << j << ' ' << x << ' ' << y << endl;
					if (s[x][y] == 'O') continue;
					if (i == x && j == y) continue;
					for (int k = 0; k < 4; k++) {
						int I = i + gox[k], J = j + goy[k], X = x + gox[k], Y = y + goy[k];
						if (s[I][J] == 'O' || s[X][Y] == '.') continue;
						// std::cout << I << ' ' << J << ' ' << X << ' ' << Y << endl;
						f[i][j][x][y] = 1;
						vis[i][j][x][y] = 1;
						q.push({i, j, x, y});
						break;
					}
				}
			}
		}
	}
	while (!q.empty()) {
		auto [i, j, x, y] = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int I = i + gox[k], J = j + goy[k], X = x + gox[k], Y = y + goy[k];
			if (s[I][J] == 'O' || s[X][Y] == 'O') continue;
			if (vis[I][J][X][Y]) continue;
			f[I][J][X][Y] = 1;
			vis[I][J][X][Y] = 1;
			q.push({I, J, X, Y});
		}
	}
	std::vector ans(n + 1, std::vector(m + 1, int()));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'O') continue;
			ans[i][j] = 1;
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					if (s[x][y] == 'O') continue;
					if (i == x && j == y) continue;
					if (f[i][j][x][y] == 0) ans[i][j] = 0;
				}
			}
		}
	}
	int ANS = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ANS += ans[i][j];
		}
	}
	std::cout << ANS << endl;
}

int main() {
	// Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
		     	 	  	 				 					  	 			