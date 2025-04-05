#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls x << 1
#define rs x << 1 | 1
#define int long long
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 2000010;
inline int read() {
    int sym = 0, res = 0; char ch = 0;
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct TREE{
    int l, r, len, cnt;
} tree[N];
struct node{
    int rn, l, r, t;
} pos[N];
int n, m, cnt, rk[N];
void pushup(int l, int r, int x) {
    if (tree[x].cnt){
        tree[x].len = rk[r + 1] - rk[l];
    } else {
        tree[x].len = tree[ls].len + tree[rs].len;
    }
}
void add(int x, int l, int r, int ln, int rn, int t){
    if (ln <= l && r <= rn) {
        tree[x].cnt += t; pushup(l, r, x); return;
    }int mid = l + r >> 1;
    if (mid >= ln) add(ls, l, mid, ln, rn, t);
    if (mid + 1 <= rn) add(rs, mid + 1, r, ln, rn, t);
    pushup(l, r, x);
}
bool cmp(node a, node b) {
    return a.y < b.y;
}
signed main() {
    n=read();
    for (int i = 1; i <= n; i++) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        pos[(i << 1) - 1] = (node){y1, x1, x2, +1};
        rk[(i << 1) - 1] = x1;
        pos[i << 1] = (node){y2, x1, x2, -1};
        rk[i << 1] = x2;
    }
    n <<= 1;
    sort(rk + 1, rk + n + 1);
    sort(pos + 1, pos + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        pos[i].l = lower_bound(rk + 1, rk + n + 1, pos[i].l) - rk;
        pos[i].r = lower_bound(rk + 1, rk + n + 1, pos[i].r) - rk;
    }
    long long ans = 0;
    for (int i = 1; i < n;i++) {
        add(1, 1, n, pos[i].l, pos[i].r-1, pos[i].t);
        ans += tree[1].len * (pos[i+1].rn - pos[i].rn);
    }
    printf("%lld", ans);
    return 0;
}