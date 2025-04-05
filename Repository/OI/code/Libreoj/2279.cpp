#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define ls x << 1
#define rs x << 1 | 1
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
struct node {
    int l, r, mx, p;
} tr[N];
int n, m, y[N], a[N], val[N];
node merge(node a, node b) {
    if (b.l - a.r == 1 && !a.p && !b.p) return (node){a.l, b.r, max(a.mx, b.mx), 0};
    else return (node){a.l, b.r, max(a.mx, b.mx), 1};
}
void build(int x, int l, int r) {
    if (l == r) {tr[x] = (node){y[l], y[l], a[l], 0}; return;}
    int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    tr[x] = merge(tr[ls], tr[rs]);
}
node query(int x, int yl, int yr) {
    if (yl <= tr[x].l && tr[x].r <= yr) {return tr[x];}
    if (tr[ls].r >= yl && tr[rs].l <= yr) {
        return merge(query(ls, yl, yr), query(rs, yl, yr));
    }
    if (tr[ls].r >= yl) return query(ls, yl, yr);
    if (tr[rs].l <= yr) return query(rs, yl, yr);
}
int main() {
    n = read(); int mi = inf, mx = -inf;
    for (int i = 1; i <= n; i++) {
        y[i] = read(); a[i] = read(); val[y[i]] = a[i]; mi = min(mi, y[i]); mx = max(mx, y[i]);
    }
    build(1, 1, n); m = read();
    //for (int i = 1; i <= 13; i++) printf("%d %d %d %d\n", tr[i].l, tr[i].r, tr[i].mx, tr[i].p);
    for (int i = 1; i <= m; i++) {
        int l = read() + 1, r = read(); node d = query(1, max(l, mi), min(r, mx));
        //printf("%d %d %d %d\n", d.l, d.r, d.mx, d.p);
        if (!val[l - 1] || !val[r]) printf("maybe\n");
        else if (val[r] > val[l - 1]) printf("false\n");
        else printf(d.mx == val[r] ? d.p ? "maybe\n" : "true\n" : "false\n");
    }
    return 0;
}