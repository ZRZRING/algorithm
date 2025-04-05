#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define lowbit(x) (x & -x)
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 2e5 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, m, fa[N], num[N], cnt, ncnt, son[N][30], fail[N], dfn[N], siz[N];
int head[N], x[N], y[N], ans[N], tsum[N], trie[N][30], fin[N];
char ch[N];
vector <int> q[N];
void modify(int x, int t) {
    for (; x <= cnt; x += lowbit(x)) tsum[x] += t;
}
int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tsum[x];
    return res;
}
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
} 
void ins(char *ch) {
    int len = strlen(ch), u = 0;
    for (int i = 0; i < len; i++) {
        if (ch[i] == 'B') {u = fa[u]; continue;}
        if (ch[i] == 'P') {num[++ncnt] = u; fin[u] = 1; continue;}
        int v = ch[i] - 'a';
        if (!son[u][v]) trie[u][v] = son[u][v] = ++cnt, fa[cnt] = u;
        u = son[u][v];
    }
}
void dfs1(int u) {
    dfn[u] = ++cnt; siz[u] = 1;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dfs1(v); siz[u] += siz[v];
    }
}
void build() {
    queue <int> q;
    for (int i = 0; i < 26; i++) {
        if (son[0][i]) q.push(son[0][i]);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop(); add(fail[u], u);
        for (int i = 0; i < 26; i++) {
            int v = son[u][i];
            if (v) fail[v] = son[fail[u]][i], q.push(v);
            else son[u][i] = son[fail[u]][i];
        }
    }
}
void dfs2(int u) {
    modify(dfn[u], 1);
    vector <int> :: iterator it;
    if (fin[u]) {
        for (it = q[u].begin(); it != q[u].end(); it++) {
            int i = *it;
            ans[i] = query(dfn[num[x[i]]] + siz[num[x[i]]] - 1) - query(dfn[num[x[i]]] - 1);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (trie[u][i]) dfs2(trie[u][i]);
    }
    modify(dfn[u], -1);
}
int main() {
    scanf("%s", ch); ins(ch); cnt = 0; build(); cnt = 0; dfs1(0);
    n = read();
    for (int i = 1; i <= n; i++) {
        x[i] = read(); y[i] = read(); q[num[y[i]]].push_back(i);
    }
    dfs2(0);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}