#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
	int u, v, nxt, t;
} edge[N];
int n, m, head[N], cnt;
void add(int u, int v, int t) {
	edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
void dfs(int u, int last, int t) {
	fa[u] = last;
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == last) continue; dfs(v, u, edge[e].t);
	}
}
namespace W1 {
	void dfs(int u, int last) {
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue;
		}
	}
}
namespace W2 {
	void dfs(int u, int last) {
		
	}
}
int main() {
    n = read();
    for (int i = 1; i < n; i++) {
    	int u = read(), v = read(), c = read(), g = read();
    	add(u, v, c ^ g); add(v, u, c ^ g);
    }
    W1::dfs(1, 0); W2::dfs(1, 0);
    return 0;
}