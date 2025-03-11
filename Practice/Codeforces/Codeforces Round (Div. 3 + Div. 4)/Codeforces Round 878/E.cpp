#include <bits/stdc++.h>

#define int64 long long
#define mp(x, y) make_pair(x, y)

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		std::string s[2];
		std::cin >> s[0] >> s[1];
		int n = read(), m = read(), k = s[0].length();
		int vis[k + 1] = {0}, lock[k + 1] = {0}, cnt = 0;
		s[0] = " " + s[0]; s[1] = " " + s[1];
		for (int i = 1; i <= k; i++) {
			if (s[0][i] != s[1][i]) vis[i] = 1, cnt++;
		}
		std::queue<std::pair<int, int> > q;
		for (int i = 1; i <= m; i++) {
			while (!q.empty()) {
				if (i - q.front().first >= n) {
					lock[q.front().second] = 0;
					if (vis[q.front().second] == 1) cnt++; q.pop();
				} else break;
			}
			// printf("i : %d cnt : %d\n", i, cnt);
			int opt = read();
			if (opt == 1) {
				int x = read(); q.push(std::mp(i, x));
				lock[x] = 0; if (vis[x] == 1) cnt--;
			}
			if (opt == 2) {
				int c1 = read() - 1, p1 = read(), c2 = read() - 1, p2 = read();
				std::swap(s[c1][p1], s[c2][p2]);
				if (s[c1][p1] == s[c1 ^ 1][p1]) {
					if (vis[p1]) vis[p1] = 0, cnt--;
				} else {
					if (!vis[p1]) vis[p1] = 1, cnt++;
				}
				if (s[c2][p2] == s[c2 ^ 1][p2]) {
					if (vis[p2]) vis[p2] = 0, cnt--;
				} else {
					if (!vis[p2]) vis[p2] = 1, cnt++;
				}
			}
			// std::cout << s[0] << '\n' << s[1] << '\n';
			if (opt == 3) {
				printf(cnt ? "No\n" : "Yes\n");
			}
		}
	}
	return 0;
}