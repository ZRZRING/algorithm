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
int n, m, a[N];
long long dif[N];
namespace SEG {
    long long tr[N];
    #define ls x << 1
    #define rs x << 1 | 1
    void pushup(int x) {tr[x] = min(tr[ls], tr[rs]);}
    void build(int x, int l, int r) {
        if (l == r) {tr[x] = dif[l]; return;} int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r); pushup(x);
    }
    void modify(int x, int l, int r, int pos, int t) {
        if (l == r) {tr[x] += t; return;} int mid = l + r >> 1;
        if (mid >= pos) modify(ls, l, mid, pos, t); else modify(rs, mid + 1, r, pos, t); pushup(x);
    }
    bool query(int x, int l, int r, int ln, int rn) {
        if (ln <= l && r <= rn) {return tr[x] > 0;} int mid = l + r >> 1;
        if (mid >= rn) return query(ls, l, mid, ln, rn) > 0; if (mid + 1 <= ln) return query(rs, mid + 1, r, ln, rn) > 0;
        return min(query(ls, l, mid, ln, rn), query(rs, mid + 1, r, ln, rn)) > 0;
    }
}
int main() {
    n = read(); m = read(); a[1] = read();
    for (int i = 2; i <= n; i++) a[i] = read(), dif[i - 1] = 1ll * a[i] - a[i - 1];
    n--; using namespace SEG; build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt = read(), l = read(), r = read();
        if (opt == 1) {
            int t = read(); if (l != 1) modify(1, 1, n, l - 1, t); if (r != n + 1) modify(1, 1, n, r, -t);
        }
        if (opt == 2) {
            if (l == r) {puts("Yes"); continue;}
            puts(query(1, 1, n, l, r - 1) ? "Yes" : "No");
        }
    }
    return 0;
}