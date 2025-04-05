#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define alpha 0.75
#define ls tr[x][0]
#define rs tr[x][1]
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
int n, m, K, rt, ans, top, s[N], cnt;
struct Node {
    int son[2], mi[2], mx[2], p[2], siz;
    int& operator [] (int x) {return son[x];}
    bool operator < (const Node a) {return p[K] < a.p[K];}
} tr[N], S, a[N];
int dis(Node a, Node b) {return abs(a.p[0] - b.p[0]) + abs(a.p[1] - b.p[1]);}
int newnode() {if (top) return s[top--]; return ++cnt;}
void pushup(int x) {
    tr[x].siz = tr[ls].siz + tr[rs].siz + 1; for (int i = 0; i <= 1; i++) tr[x].mx[i] = tr[x].mi[i] = tr[x].p[i];
    if (ls) for (int i = 0; i <= 1; i++) tr[x].mx[i] = max(tr[x].mx[i], tr[ls].mx[i]), tr[x].mi[i] = min(tr[x].mi[i], tr[ls].mi[i]);
    if (rs) for (int i = 0; i <= 1; i++) tr[x].mx[i] = max(tr[x].mx[i], tr[rs].mx[i]), tr[x].mi[i] = min(tr[x].mi[i], tr[rs].mi[i]);
}
int build(int l, int r, int type) {
    K = type; int mid = l + r >> 1, x = newnode();
    nth_element(a + l, a + mid, a + r + 1);
    tr[x] = a[mid]; ls = rs = 0;
    if (l < mid) ls = build(l, mid - 1, type ^ 1);
    if (r > mid) rs = build(mid + 1, r, type ^ 1);
    pushup(x); return x;
}
void dfs(int x, int tot) {
    if (ls) dfs(ls, tot);
    a[tot + tr[ls].siz + 1] = tr[x]; s[++top] = x;
    if (rs) dfs(rs, tot + tr[ls].siz + 1);
}
void remake(int &x, int type) {
    if (tr[ls].siz > tr[x].siz * alpha || tr[rs].siz > tr[x].siz * alpha) {
        dfs(x, 0); x = build(1, tr[x].siz, type);
    }
}
void insert(int &x, int type) {
    K = type;
    if (!x) {
        x = newnode(); tr[x] = S; ls = rs = 0; pushup(x); return;
    }
    insert(tr[x][S < tr[x]], type ^ 1); pushup(x); remake(x, type);
}
int val(int x) {
    if (!x) return inf; int res = 0;
    for (int i = 0; i <= 1; i++) {
        res += max(0, tr[x].mi[i] - S.p[i]) + max(0, S.p[i] - tr[x].mx[i]);
    }
    return res;
}
void query(int x) {
    ans = min(ans, dis(S, tr[x])); int dl = val(ls), dr = val(rs);
    if (dl < dr) {
        if (dl < ans) query(ls); if (dr < ans) query(rs);
    } else {
        if (dr < ans) query(rs); if (dl < ans) query(ls);
    }
}
int main() { //file();
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i].p[0] = read(); a[i].p[1] = read();
    }
    rt = build(1, n, 0);
    for (int i = 1; i <= m; i++) {
        int opt = read(); S.p[0] = read(); S.p[1] = read();
        if (opt == 1) insert(rt, 0);
        if (opt == 2) ans = inf, query(rt), printf("%d\n", ans);
    }
    return 0;
}