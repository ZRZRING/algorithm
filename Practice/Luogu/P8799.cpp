#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10;

int main() {
	int n = read(), m = read(), M = 0, vis[N] = {0};
	bool ans[N] = {0};
	for (int i = 1; i <= n; i++) {
		int x = read(); vis[x]++; M = std::max(x, M);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= M; j += i) {
			ans[j / i] = (vis[i] && vis[j]);
		}
	}
	bool flag = 0;
	for (int i = 1; i <= M; i++) if (vis[i] >= 2) flag = 1;
	ans[1] = flag;
	for (int i = 1; i <= m; i++) {
		int x = read();
		printf(ans[x] ? "YES\n" : "NO\n");
	}
	return 0;
}