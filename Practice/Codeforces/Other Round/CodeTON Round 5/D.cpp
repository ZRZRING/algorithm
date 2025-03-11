#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int inf = 0x3f3f3f3f;

int main() {
	int n = read(), m = read(), e[n + 1][n + 1];
	memset(e, inf, sizeof(e));
	int64 sum = 0;
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), t = read();
		e[u][v] = t; e[v][u] = t;
	}
	bool flag = 1;
	std::string s(n, '1'); s[n - 1] = '0';
	std::vector<std::pair<std::string, int> > ans;
	while (1) {
		int min = inf;
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (s[u - 1] != s[v - 1]) min = std::min(min, e[u][v]);
			}
		}
		if (min == inf) {flag = 0; break;}
		if (min) {
			ans.push_back(std::make_pair(s, min)); sum += min;
		}
		bool b = 0;
		std::vector<std::pair<int, int> > cls;
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (e[u][v] == inf) continue;
				if (s[u - 1] != s[v - 1]) {
					e[u][v] -= min;
					if (!e[u][v]) {
						cls.push_back(std::make_pair(u, v));
						if (u == 1 || v == 1) b = 1;
					}
				}
			}
		}
		for (auto x : cls) {
			int u = x.first, v = x.second;
			e[u][v] = inf; s[u - 1] = '0'; s[v - 1] = '0';
		}
		if (b) break;
	}
	if (!flag) printf("inf\n");
	else {
		printf("%lld %d\n", sum, ans.size());
		for (auto x : ans) {
			std::cout << x.first << ' ' << x.second << '\n';
		}
	}
	return 0;
}