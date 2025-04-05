#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (x << 1)
#define rs (x << 1 | 1)
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 5e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct node {
    int l, r, len;
    bool operator < (const node &a) const {return len < a.len;}
} a[N];
int n, m, tmp[N];
int tmax[N], tag[N];
void update(int x, int l, int r, int t) {
    tmax[x] += t; tag[x] += t;
}
void pushup(int x) {
    tmax[x] = max(tmax[ls], tmax[rs]);
}
void pushdown(int x, int l, int r, int mid) {
    if (tag[x]) {
        update(ls, l, mid, tag[x]);
        update(rs, mid + 1, r, tag[x]);
        tag[x] = 0;
    }
}
void modify(int x, int l, int r, int ln, int rn, int t) {
    if (ln <= l && r <= rn) {
        update(x, l, r, t); return;
    }
    int mid = l + r >> 1; pushdown(x, l, r, mid);
    if (mid >= ln) modify(ls, l, mid, ln, rn, t);
    if (mid + 1 <= rn) modify(rs, mid + 1, r, ln, rn, t);
    pushup(x);
}
int main() {
    n = read(); m = read(); int tn = 0;
    for (int i = 1; i <= n; i++) {
        a[i].l = read(); a[i].r = read();
        a[i].len = a[i].r - a[i].l;
        tmp[++tn] = a[i].l; tmp[++tn] = a[i].r;
    }
    sort(tmp + 1, tmp + tn + 1);
    tn = unique(tmp + 1, tmp + tn + 1) - tmp - 1;
    for (int i = 1; i <= n; i++) {
        a[i].l = lower_bound(tmp + 1, tmp + tn + 1, a[i].l) - tmp;
        a[i].r = lower_bound(tmp + 1, tmp + tn + 1, a[i].r) - tmp;
    }
	sort(a + 1, a + n + 1); int ans = inf, l = 1, r = 0;
    while (l <= n) {
        while (r < n && tmax[1] < m) {
            r++; modify(1, 1, tn, a[r].l, a[r].r, 1);
        }
        if (tmax[1] >= m) {
            ans = min(ans, a[r].len - a[l].len);
        }
        modify(1, 1, tn, a[l].l, a[l].r, -1); l++;
    }
    if (ans == inf) printf("-1"); else printf("%d", ans);
    return 0;
}