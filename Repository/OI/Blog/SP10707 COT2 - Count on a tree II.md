树上莫队板子题，就是把区间数颜色丢到了树上

考虑把树映射到序列上，将链转化成序列，括号序可以满足这一要求，建出来括号序后，记$l_i$为第一括号序，$r_i$为第二括号序，对于询问一条链$x,y$，设$l_x < l_y$，如果$r_x < l_y$，区间就设置为$[r_x, l_y]$，否则设置为$[l_x, l_y]$

括号序中出现一次的点加上$lca(x, y)$的贡献即为答案

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct EDGE {int u, v, nxt;} edge[N];

struct QRY {int l, r, d, id;} qry[N];

int n, m, cur, head[N], b[N], col[N], vis[N], cnt[N], fst[N], fin[N], L[N], R[N], bel[N], ans[N], to[N], res;

void add(int u, int v) {edge[++cur] = (EDGE){u, v, head[u]}; head[u] = cur;}

namespace LCA {
	int cur, fa[N], son[N], top[N], siz[N], dep[N], dfn[N];

	void dfs1(int u, int last) {
		dep[u] = dep[last] + 1; fa[u] = last; siz[u] = 1;
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; dfs1(v, u);
			siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
		}
	}

	void dfs2(int u, int front) {
		dfn[u] = ++cur; top[u] = front; if (son[u]) dfs2(son[u], front);
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
		}
	}

	int lca(int x, int y) {
		while (top[x] != top[y]) dep[top[x]] > dep[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
		return dep[x] < dep[y] ? x : y;
	}
}

void init() {
	int B = sqrt(n), C = 0;
	for (int i = 1; i <= n; i += B) {
		L[++C] = i; R[C] = i + B - 1;
	}
	for (int i = 1; i <= C; i++) {
		for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
	}
}

void dfs(int u, int last) {
	fst[u] = ++cur; to[cur] = u;
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == last) continue; dfs(v, u);
	}
	fin[u] = ++cur; to[cur] = u;
}

void upd(int x) {
	vis[x] ^= 1; vis[x] ? res += !cnt[col[x]]++ : res -= !--cnt[col[x]];
}

bool cmp(QRY a, QRY b) {
	return bel[a.l] == bel[b.l] ? bel[a.l] & 1 ? a.r < b.r : a.r > b.r : bel[a.l] < bel[b.l];
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) col[i] = read(), b[i] = col[i];
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); add(u, v); add(v, u);
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) col[i] = lower_bound(b + 1, b + n + 1, col[i]) - b;
	n = cur; init(); LCA::dfs1(1, 0); LCA::dfs2(1, 1); cur = 0; dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read(), d = LCA::lca(x, y); if (fst[x] > fst[y]) swap(x, y);
		if (d == x) qry[i] = (QRY){fin[x], fst[y], d, i}; else qry[i] = (QRY){fin[x], fst[y], d, i};
	}
	sort(qry + 1, qry + m + 1, cmp); int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < qry[i].l) upd(to[l++]);
		while (l > qry[i].l) upd(to[--l]);
		while (r < qry[i].r) upd(to[++r]);
		while (r > qry[i].r) upd(to[r--]);
		ans[qry[i].id] = res + !cnt[col[qry[i].d]];
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
```