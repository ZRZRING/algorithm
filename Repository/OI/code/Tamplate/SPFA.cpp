#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
using namespace std;
void file() {
	freopen("read.in", "r", stdin);
	freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
inline int read() {
	int sym = 0, res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}
struct EDGE {
	int u, v, nxt, dis;
} edge[N];
int n, m, s, head[N], cnt, dis[N], vis[N];
queue<int>q;
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void SPFA() {
	for (int i = 1; i <= n; i++) dis[i] = 2147483647;
	q.push(s); dis[s] = 0; vis[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v;
			if (dis[v] > dis[u] + edge[e].dis) {
				dis[v] = dis[u] + edge[e].dis;
				if (vis[v]) continue; q.push(v); vis[v] = 1;
			}
		}
	}
}
int main() {
	n = read(); m = read(); s = read();
	for (int i = 1, u, v, t; i <= m; i++) {
		u = read(), v = read(), t = read(); add(u, v, t);
	}
	SPFA();
	for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
	return 0;
}