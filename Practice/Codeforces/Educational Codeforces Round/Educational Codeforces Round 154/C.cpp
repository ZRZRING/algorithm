#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		std::string s;
		std::cin >> s;
		int n = s.length(), cnt = 0, u = 0, pre[n + 1] = {0}, vis[n + 1] = {0};
		std::vector<std::vector<int> > edge(1);
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '+') {
				int v = ++cnt;
				edge.push_back(std::vector<int>());
				edge[u].push_back(v);
				pre[v] = u; u = v;
				continue;
			}
			if (s[i] == '-') {
				u = pre[u]; continue;
			}
			if (vis[u]) {
				if (vis[u] != s[i] - '0' + 1) flag = 1;
			} else {
				vis[u] = s[i] - '0' + 1;
			}
		}
		// for (int i = 0; i < n; i++) printf("%d ", vis[i]); puts("");
		if (vis[0] == 1) {printf("NO\n"); continue;}
		for (int i = 1; i <= cnt; i++) {
			if (pre[i] == 0 && vis[i] == 1) flag = 1;
		}
		if (flag) {printf("NO\n"); continue;}
		std::function<bool(int, bool)> dfs = [&](int u, bool c) -> bool {
			if (c && vis[u] == 2) return 1;
			if (vis[u] == 1) c = 1;
			for (auto v : edge[u]) {
				if (dfs(v, c)) return 1;
			}
			return 0;
		};
		if (dfs(0, 0)) printf("NO\n"); else printf("YES\n");
	}
	return 0;
}