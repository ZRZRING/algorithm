#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define int long long
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
    int u, v, nxt;
} edge[N];
int n, m, cnt, head[N], val[N], ans, s[N];
priority_queue<int>q[N];
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}
void merge(int x, int y) {
    if (q[x].size() < q[y].size()) swap(q[x], q[y]); int top = 0;
    while (q[y].size()) {
        s[++top] = max(q[x].top(), q[y].top()); q[x].pop(); q[y].pop();
    }
    for (int i = 1; i <= top; i++) q[x].push(s[i]);
}
void dfs(int u) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dfs(v); merge(u, v);
    }
    q[u].push(val[u]);
}
signed main() {
    n = read();
    for (int i = 1; i <= n; i++) val[i] = read();
    for (int v = 2; v <= n; v++) {
        int u = read(); add(u, v);
    }
    dfs(1);
    while (q[1].size()) {
        ans += q[1].top(); q[1].pop();
    }
    printf("%lld", ans);
    return 0;
}