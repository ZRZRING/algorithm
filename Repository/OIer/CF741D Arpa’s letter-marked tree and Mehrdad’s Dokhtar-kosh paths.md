> 一棵树边上有字母(a-v)，一条简单路径被称为Dokhtar-kosh当且仅当路径上的字符经过重新排序后可以变成一个回文串，求每个子树中最长的Dokhtar-kosh路径的长度

首先考虑如何表示Dokhtar-kosh string，因为一个回文串最多有一个出现奇数次的字符，使用hash思想，我们把每一种字母表示成仅一位上是1且互不相同的二进制数，一个字符串的权值定义为该字符串所有字母表示的数的异或和，若一个字符串的权值在二进制下只有一个1则该字符串为Dokhtar-kosh string

记str(x,y)表示x到y的链组成的字符串的权值，考虑树上差分，str(u,v)满足上述性质，等价于str(1,u)异或str(1,v)​满足上述性质，于是预处理出所有的str(1,i)，每次在子树中匹配str(1,j)，这样复杂度是所有子树大小和为$\mathcal{O}(n^2)$，用dsu on tree，每个节点只遍历所有轻儿子的子树，即可优化到$\mathcal{O}(n log n)$

注意mx数组要初始化为无穷小

```cpp
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
const int N = 1e6 + 10, V = 2e7 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt, dis;
} edge[N];
int n, m, head[N], cnt, siz[N], son[N], po[N], L[N], R[N], dis[N], ans[N], mx[V], dep[N];
char ch[N];
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void dfs1(int u) {
    siz[u] = 1; L[u] = ++cnt; po[cnt] = u;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dis[v] = dis[u] ^ edge[e].dis; dep[v] = dep[u] + 1;
        dfs1(v); siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
    }
    R[u] = cnt;
}
void dfs2(int u, bool keep) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == son[u]) continue;
        dfs2(v, 0); ans[u] = max(ans[u], ans[v]);
    }
    if (son[u]) dfs2(son[u], 1), ans[u] = max(ans[u], ans[son[u]]);
    ans[u] = max(ans[u], mx[dis[u]] - dep[u]);
    for (int i = 0; i <= 21; i++) ans[u] = max(ans[u], mx[dis[u] ^ 1 << i] - dep[u]);
    mx[dis[u]] = max(mx[dis[u]], dep[u]);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == son[u]) continue;
        for (int i = L[v], x = po[i]; i <= R[v]; i++, x = po[i]) {
            ans[u] = max(ans[u], mx[dis[x]] + dep[x] - 2 * dep[u]);
            for (int i = 0; i <= 21; i++) ans[u] = max(ans[u], mx[dis[x] ^ 1 << i] + dep[x] - 2 * dep[u]);
        }
        for (int i = L[v], x = po[i]; i <= R[v]; i++, x = po[i]) {
            mx[dis[x]] = max(mx[dis[x]], dep[x]);
        }
    }
    if (!keep) {for (int i = L[u], x = po[i]; i <= R[u]; i++, x = po[i]) mx[dis[x]] = -inf;}
}
int main() {
    n = read(); memset(mx, 128, sizeof(mx));
    for (int v = 2; v <= n; v++) {
        int u = read(); char t = getchar(); add(u, v, 1ll << t - 'a');
    }
    dep[1] = 1; dfs1(1); dfs2(1, 1); for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
```

