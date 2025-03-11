#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define int64 long long
#define endl '\n'

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> s(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i] + " ";
	}
	s[n + 1].resize(m + 2);
	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'S') {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (1) {
		std::vector<std::vector<int> > to(n + 1, std::vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			int t = 0;
			for (int j = m; j >= 1; j--) {
				if (s[i][j] != '#') {
					if (!t) t = j;
					to[i][j] = t;
				} else {
					t = 0;
				}
			}
		}
		std::vector<PII> gap(m + 1);
		int L = y, R = y;
		while (L - 1 >= 1 && s[x][L - 1] == '.') L--;
		while (R + 1 <= m && s[x][R + 1] == '.') R++;
		#define U first
		#define D second
		for (int j = L; j <= R; j++) {
			gap[j] = {x, x};
			while (gap[j].U - 1 >= 1 && s[gap[j].U - 1][j] != '#') gap[j].U--;
			while (gap[j].D + 1 <= n && s[gap[j].D + 1][j] != '#') gap[j].D++;
		}
		for (int i = L; i <= y; i++) {
			for (int j = gap[i].U; j <= gap[i].D; j++) {
				if (j == x) continue;
				for (int k = y; k <= std::min(to[j][i], R); k++) {
					if (i == k) continue;
					// std::cout << gap[k].U << ' ' << gap[k].D << endl;
					if (gap[k].U <= j && j <= gap[k].D) {
						// std::cout << i << ' ' << j << ' ' << k << endl;
						std::cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	if (1) {
		std::vector<std::vector<int> > to(n + 1, std::vector<int>(m + 1));
		for (int j = 1; j <= m; j++) {
			int t = 0;
			for (int i = n; i >= 1; i--) {
				if (s[i][j] != '#') {
					if (!t) t = i;
					to[i][j] = t;
				} else {
					t = 0;
				}
			}
		}
		std::vector<PII> gap(n + 1);
		int U = x, D = x;
		while (U - 1 >= 1 && s[U - 1][y] == '.') U--;
		while (D + 1 <= n && s[D + 1][y] == '.') D++;
		#define L first
		#define R second
		for (int i = U; i <= D; i++) {
			gap[i] = {y, y};
			while (gap[i].L - 1 >= 1 && s[i][gap[i].L - 1] != '#') gap[i].L--;
			while (gap[i].R + 1 <= m && s[i][gap[i].R + 1] != '#') gap[i].R++;
		}
		for (int i = U; i <= x; i++) {
			for (int j = gap[i].L; j <= gap[i].R; j++) {
				if (j == y) continue;
				for (int k = x; k <= std::min(to[i][j], D); k++) {
					if (i == k) continue;
					// std::cout << gap[k].L << ' ' << gap[k].R << endl;
					if (gap[k].L <= j && j <= gap[k].R) {
						// std::cout << i << ' ' << j << ' ' << k << endl;
						std::cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	std::cout << "No" << endl;
	return 0;
}
