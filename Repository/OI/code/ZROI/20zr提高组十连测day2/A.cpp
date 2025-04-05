#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 2e6 + 10, inf = 1e12;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct NODE {int cost, mx;} buy[N];
struct TREE {long long cnt, sum;} tr[N];
struct TAG {int add, cls;} tag[N];
int n, m, a[N];
long long sum[N], mx[N];
bool cmp(NODE a, NODE b) {return a.cost < b.cost;}
void pushup(int x) {
    tr[x] = (TREE){tr[ls].cnt + tr[rs].cnt, tr[ls].sum + tr[rs].sum};
}
void update(int x, int l, int r, int t) {
    tr[x] = (TREE){tr[x].cnt + t * (mx[r] - mx[l - 1]), tr[x].sum + t * (sum[r] - sum[l - 1])}; tag[x].add += t;
}
void clear(int x) {
    tag[x] = (TAG){0, 1}; tr[x] = (TREE){0, 0};
}
void pushdown(int x, int l, int r, int mid) {
    if (tag[x].cls) {
        clear(ls); clear(rs); tag[x].cls = 0;
    }
    if (tag[x].add) {
        update(ls, l, mid, tag[x].add); update(rs, mid + 1, r, tag[x].add); tag[x].add = 0;
    }
}
int query(int x, int l, int r, int t) {
    if (l == r) {
        tr[x].cnt -= t; tr[x].sum -= t * buy[l].cost;
        return t * buy[l].cost;
    }
    int mid = l + r >> 1; int res; pushdown(x, l, r, mid);
    if (t <= tr[ls].cnt) res = query(ls, l, mid, t);
    else res = tr[ls].sum + query(rs, mid + 1, r, t - tr[ls].cnt), clear(ls);
    pushup(x); return res;
}
signed main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) {
        buy[i].cost = read(); buy[i].mx = read();
    }
    sort(buy + 1, buy + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (buy[i].mx == -1) {m = i; mx[i] = mx[i - 1] + inf; break;}
        mx[i] = mx[i - 1] + buy[i].mx;
        sum[i] = sum[i - 1] + buy[i].mx * buy[i].cost;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        update(1, 1, m, 1); ans += query(1, 1, m, a[i]);
    }
    printf("%lld", ans);
    return 0;
}