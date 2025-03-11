#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct EDGE {
	int u, v, nxt;
} edge[N];

int n, m, cnt, head[N], ans, dep[N], vis[N], res, mx, tot[N];

void add(int u, int v) {
	edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}

void dfs(int u, int last) {
	dep[u] = dep[last] + 1; if (vis[u]) mx = max(mx, dep[u]), cnt++, tot[dep[u]]++;
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == last) continue; dfs(v, u);
	}
}

int solve(int u) {
	cnt = res = 0; dfs(u, 1);
	for (int i = 1; i <= mx - 1; i++) {
		if (!tot[i]) res++; tot[i + 1] += max(0, tot[i] - 1); tot[i] = 0;
	}
	tot[mx] = 0; if (cnt) cnt--;
	return mx + cnt - max(0, mx - 1 - res);
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= m; i++) vis[read()] = 1;
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); add(u, v); add(v, u);
	}
	for (int e = head[1]; e; e = edge[e].nxt) {
		int v = edge[e].v; ans = max(ans, solve(v));
	}
	printf("%d", ans);
	return 0;
}