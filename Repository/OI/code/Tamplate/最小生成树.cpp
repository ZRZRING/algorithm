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
	int u, v, dis;
	bool operator < (const EDGE &a) const {return dis < a.dis;}
} edge[N];
int n, m, fa[N], ans;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	n = read(); m = read();
	for (int i = 1; i <= m; i++) {
		edge[i].u = read(); edge[i].v = read(); edge[i].dis = read();
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1, edge + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = find(edge[i].u), v = find(edge[i].v), dis = edge[i].dis;
		if (u != v) fa[v] = u, ans += dis;
	}
	printf("%d", ans);
	return 0;
}