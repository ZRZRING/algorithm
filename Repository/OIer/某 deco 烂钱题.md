比赛链接 - https://www.jisuanke.com/contest/13416

#### A. 幻影之啸

题目链接 - https://nanti.jisuanke.com/t/T3250

> 求和文本串可以通过添加一个字符或删掉一个字符的模式串

题意题，数据范围也不大，直接暴力找添加或删掉的是哪个字符就可以了

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, ans;

char ch[N], xcw[N];

bool check(char a[], char b[]) {
    bool f1 = 0; int la = strlen(a), lb = strlen(b);
    for (int j = 1; j <= m; j++) {
        bool f2 = 1;
        for (int p1 = 1, p2 = 1; ; p1++, p2++) {
            if (p1 == j) p1++; if (p1 > la || p2 > lb) break;
            if (xcw[p1] != ch[p2]) {f2 = 0; break;}
        }
        if (f2) {f1 = 1; break;}
    }
    return f1;
}

int main() {
    #ifdef ONLINE_JUDGE
       freopen("illusion.in", "r", stdin);
       freopen("illusion.out", "w", stdout);
    #endif
    scanf("%s", xcw + 1); n = read(); m = strlen(xcw + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch + 1); int len = strlen(ch + 1);
        if (m == len) {
            int flag = 1;
            for (int i = 1; i <= len; i++) if (xcw[i] != ch[i]) {flag = 0; break;}
            if (flag) ans++;
        }
        if (m - len == 1) ans += check(xcw, ch);
        if (len - m == 1) ans += check(ch, xcw);
    }
    printf("%d", ans);
    return 0;
}
```

#### B. 宇宙蓝色闪光

题目链接 - https://nanti.jisuanke.com/t/T3251

> 在X建立一个炸弹塔，该塔可以对其他所有点等概率爆破，每次爆破能使得爆破点到该炸弹塔的路径都被炸

> 求使得A期望被炸次数最多前提下B期望被炸次数最少的X的位置共有多少个

考虑以A为根，对于每棵子树，爆破的点在该子树外才能炸到A点，那么在A的最小子树内建立X可以保证A期望被炸次数最多，B同理，最后整合两个答案时分类讨论即可

注意如果要按照我这个写法的话，在A的最小的子树内只有一个B是需要特判的

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt;
} edge[N];

int n, m, cnt, head[N], siz[N], A, B, sonA, sonB, sizA, sizB, ans, vis[N];

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

void dfs(int u, int last, int t) {
    siz[u] = 1; vis[u] += t;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last || v == A) continue; dfs(v, u, t); siz[u] += siz[v];
    }
}

int main() {
    #ifdef ONLINE_JUDGE
       freopen("halloween.in", "r", stdin);
       freopen("halloween.out", "w", stdout);
    #endif
    n = read(); A = read(); B = read();
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    siz[0] = inf; ans = 0;
    for (int e = head[A]; e; e = edge[e].nxt) {
        int v = edge[e].v; dfs(v, A, 0);
        if (siz[v] == siz[sonA]) ans += siz[v];
        if (siz[v] < siz[sonA]) sonA = v, ans = siz[v];
    }
    dfs(sonA, A, 1); if (!vis[B]) {printf("%d", ans); return 0;}
    if (siz[sonA] == 1 && sonA == B) {printf("%d", n - 2); return 0;}
    siz[0] = 0; ans = 0;
    for (int e = head[B]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == A) continue; dfs(v, B, 0);
        if (siz[v] == siz[sonB]) ans += siz[v];
        if (siz[v] > siz[sonB]) sonB = v, ans = siz[v];
    }
    printf("%d", ans);
    return 0;
}
```

#### C. 魔镜啊魔镜

题目链接 - https://nanti.jisuanke.com/t/T3252

> 多次询问一棵树上x到y间的关键路径有多少条

记每条关键路径的两个点为u和v，树上每个点的dfn为$l_i$，该点子树内最大的dfn为$r_i$，那么可以把关键路径分成两类讨论，设$l_u < l_v$，$l_x < l_y$

若$r_u < r_u$，u和v没有包含关系，对于两个点分别在u和v的子树的询问有贡献，即对$x \in [l_u,r_u], y \in [l_v,  r_v]$的询问有贡献

若$r_u > r_v$，v在u的子树内，记u到v这条链上u的儿子为d，对于两个点分别在v的子树内和除去d的子树的整棵树的询问有贡献，即对$x \in [1, l_d - 1] \cap [r_d + 1, n], y \in [l_v, r_v]$的询问有贡献

把上述有贡献的区间用差分拆成同一种偏序关系，跑一个二维数点就可以了

```cpp
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

struct NODE {
    int x, y, t, id;
    bool operator < (const NODE &a) const {return x == a.x ? y == a.y ? id < a.id : y < a.y : x < a.x;}
} dat[N], _dat[N];

struct EDGE {
    int u, v, nxt;
} edge[N];

int n, m, cnt, ans[N], l[N], r[N], fa[N], head[N];

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

struct TREE {
    int fa[N], top[N], son[N], siz[N], dep[N], cnt;
    void dfs1(int u, int last) {
        fa[u] = last; dep[u] = dep[last] + 1; siz[u] = 1; son[u] = 0;
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; if (v == last) continue; dfs1(v, u);
            siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }
    void dfs2(int u, int front) {
        top[u] = front; l[u] = ++cnt; if (son[u]) dfs2(son[u], front);
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
        }
        r[u] = cnt;
    }
    int find(int x, int y) {
        while (top[x] != top[y]) {y = top[y]; if (fa[y] == x) return y; y = fa[y];} return son[x];
    }
} T;

void cdq(int l, int r) {
    if (l >= r) return; int mid = l + r >> 1, res = 0;
    cdq(l, mid); cdq(mid + 1, r); int p = l, p1 = l, p2 = mid + 1;
    while (p2 <= r) {
        while (p1 <= mid && dat[p1].y <= dat[p2].y) {
            res += dat[p1].t, _dat[p++] = dat[p1++];
        }
        ans[dat[p2].id] += res; _dat[p++] = dat[p2++];
    }
    for (int i = p1; i <= mid; i++) _dat[p++] = dat[i];
    for (int i = l; i <= r; i++) dat[i] = _dat[i];
}

int main() {
    #ifdef ONLINE_JUDGE
       freopen("mirror.in", "r", stdin);
       freopen("mirror.out", "w", stdout);
    #endif
    n = read(); m = read(); int q = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    T.dfs1(1, 0); T.dfs2(1, 1); n = 0;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(); if (l[u] > l[v]) swap(u, v);
        if (r[u] < r[v]) {
            dat[++n] = (NODE){l[u], l[v], 1, 0};
            dat[++n] = (NODE){r[u] + 1, l[v], -1, 0};
            dat[++n] = (NODE){l[u], r[v] + 1, -1, 0};
            dat[++n] = (NODE){r[u] + 1, r[v] + 1, 1, 0};
        } else {
            int d = T.find(u, v);
            dat[++n] = (NODE){1, l[v], 1, 0};
            dat[++n] = (NODE){1, r[v] + 1, -1, 0};
            dat[++n] = (NODE){l[d], l[v], -1, 0};
            dat[++n] = (NODE){l[d], r[v] + 1, 1, 0};
            dat[++n] = (NODE){l[v], r[d] + 1, 1, 0};
            dat[++n] = (NODE){r[v] + 1, r[d] + 1, -1, 0};
        }
    }
    for (int i = 1; i <= q; i++) {
        int u = read(), v = read(); if (l[u] > l[v]) swap(u, v); dat[++n] = (NODE){l[u], l[v], 0, i};
    }
    sort(dat + 1, dat + n + 1); cdq(1, n);
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
```

#### D. 新年炸裂

题目链接 - https://nanti.jisuanke.com/t/T3253

> 求最短的包含1号点的环，n <= 10000，m <= 40000

把与1相连的点二进制分组，把其中一组点的dis初始化为到1的边权，求一个多源最短路，最后用另一组点的dis去和ans取max就行了，这样能保证每个点都能作为起点和终点各至少一次

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define abs(x) ((x) < 0 ? -(x) : (x))
#define mp(x, y) make_pair(x, y)

using namespace std;

const int N = 1e4 + 10, M = 4e4 + 10;

const long long inf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt, dis;
} edge[M << 1];

int n, m, cnt, tot, head[N], s[N], val[N];

long long dis[N];

bool vis[N];

void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}

queue<int>q;

void spfa() {
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v, d = edge[e].dis; if (v == 1) continue;
            if (dis[u] + d < dis[v]) {
                dis[v] = dis[u] + d; if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
        vis[u] = 0;
    }
}

int main() {
    #ifdef ONLINE_JUDGE
        freopen("burst.in", "r", stdin);
        freopen("burst.out", "w", stdout);
    #endif
    int T = read();
    while (T--) {
        n = read(); m = read(); memset(head, 0, sizeof(head)); cnt = 0; tot = 0;
        for (int i = 1; i <= m; i++) {
            int u = read(), v = read(), t = read(); add(u, v, t); add(v, u, t);
            if (u == 1) s[++tot] = v, val[tot] = t; if (v == 1) s[++tot] = u, val[tot] = t;
        }
        long long ans = inf;
        for (int B = 0; B <= 13; B++) {
            memset(dis, 0x3f, sizeof(dis)); memset(vis, 0, sizeof(vis));
            int flag = 0;
            for (int i = 1; i <= tot; i++) if (s[i] & 1 << B) {
                q.push(s[i]); dis[s[i]] = val[i]; vis[s[i]] = 1; flag++;
            }
            if (!flag || flag == tot) continue; spfa();
            for (int i = 1; i <= tot; i++) if ((s[i] & 1 << B) == 0) {
                ans = min(ans, dis[s[i]] + val[i]);
            }
        }
        printf("%lld\n", ans == inf ? -1 : ans);
    }
    return 0;
}
```