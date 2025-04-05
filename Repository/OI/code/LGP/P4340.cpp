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
const int N = 1e6 + 10, inf = 1e9, dsq = 1e9 + 7;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, a[N], m3[N];
namespace SEG {
    int ans[N], mul[N];
    #define ls x << 1
    #define rs x << 1 | 1
    void pushup(int x) {
        mul[x] = 1ll * mul[ls] * mul[rs] % dsq;
        ans[x] = (ans[ls] + 1ll * ans[rs] * mul[ls] % dsq) % dsq;
    }
    void build(int x, int l, int r) {
        if (l == r) {
            mul[x] = a[l]; if (l == n) ans[x] = a[l]; else ans[x] = 2ll * a[l] * m3[n - l - 1] % dsq;
            return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void modify(int x, int l, int r, int pos, int t) {
        if (l == r) {
            mul[x] = t; if (l == n) ans[x] = t; else ans[x] = 2ll * t * m3[n - l - 1] % dsq;
            return;
        }
        int mid = l + r >> 1;
        if (mid >= pos) modify(ls, l, mid, pos, t);
        else modify(rs, mid + 1, r, pos, t);
        pushup(x);
    }
}
int main() {
    n = read(); m = read(); m3[0] = 1;
    for (int i = 1; i <= n; i++) a[i] = read(), m3[i] = 3ll * m3[i - 1] % dsq;
    using namespace SEG; build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int x = read(), t = read();
        modify(1, 1, n, x, t); printf("%d\n", ans[1]);
    }
    return 0;
}