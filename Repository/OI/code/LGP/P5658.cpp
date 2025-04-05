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
const int N = 2e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
	int u, v, nxt;
} edge[N];
int n, m, head[N], cnt, fa[N], s[N], top;
long long res[N]; bool brk[N]; char ch[N];
void add(int u, int v) {
	edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}
void dfs(int u) {
    int pd = 0, t; res[u] = res[fa[u]];
	if (brk[u]) s[++top] = 0;
    else {
        if (top) {t = s[top]; --top; res[u] += ++s[top]; pd = 1;}
        else {t = s[0]; s[0] = 0;}
    }
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; dfs(v);
	}
	if (brk[u]) --top;
	else {
		if (pd) {--s[top]; ++top; s[top] = t;} else s[0] = t;
    }
}
int main() {
    n = read(); scanf("%s", ch + 1);
    for (int i = 1; i <= n; i++) brk[i] = ch[i] == '(';
    for (int v = 2; v <= n; v++) {
    	int u = read(); add(u, v); fa[v] = u;
    }
    dfs(1); long long ans = 0;
    for (int i = 1; i <= n; i++) ans ^= 1ll * res[i] * i;
    printf("%lld\n", ans);
    return 0;
}