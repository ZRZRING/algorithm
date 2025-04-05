#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define int long long
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
int n, m, a[N];
struct TREE {
    int sum[N], tag[N], mx[N], mi[N];
    #define ls x << 1
    #define rs x << 1 | 1
    void update(int x) {
        sum[x] = sum[ls] + sum[rs];
        mx[x] = max(mx[ls], mx[rs]);
        mi[x] = min(mi[ls], mi[rs]);
    }
    void modify(int x, int l, int r, int t) {
        sum[x] += t * (r - l + 1);
        tag[x] += t; mi[x] += t; mx[x] += t;
    }
    void pushdown(int x, int l, int r, int mid) {
        if (!tag[x]) return;
        modify(ls, l, mid, tag[x]); modify(rs, mid + 1, r, tag[x]);
        tag[x] = 0;
    }
    void build(int x, int l, int r) {
        if (l == r) {
            sum[x] = mx[x] = mi[x] = a[l]; return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        update(x);
    }
    void add(int x, int l, int r,int ln, int rn, int t) {
        if (ln <= l && r <= rn) {
            modify(x, l, r, t); return;
        }
        int mid = l + r >> 1; pushdown(x, l, r, mid);
        if (mid >= ln) add(ls, l, mid, ln, rn, t);
        if (mid + 1 <= rn) add(rs, mid + 1, r, ln, rn, t);
        update(x);
    }
    void chu(int x, int l, int r, int ln, int rn, int t) {
        if (ln <= l && r <= rn) {
            int A, B;
            if (mx[x] < 0) A = (mx[x] - t + 1) / t; else A = mx[x] / t;
            if (mi[x] < 0) B = (mi[x] - t + 1) / t; else B = mi[x] / t;
            if (A - mx[x] == B - mi[x]) {modify(x, l, r, A - mx[x]); return;}
        }
        int mid = l + r >> 1; pushdown(x, l, r, mid);
        if (mid >= ln) chu(ls, l, mid, ln, rn, t);
        if (mid + 1 <= rn) chu(rs, mid + 1, r, ln, rn, t);
        update(x);
    }
    int query_min(int x, int l, int r, int ln, int rn) {
        if (ln <= l && r <= rn) return mi[x];
        int mid = l + r >> 1, res = inf; pushdown(x, l, r, mid);
        if (mid >= ln) res = min(res, query_min(ls, l, mid, ln, rn));
        if (mid + 1 <= rn) res = min(res, query_min(rs, mid + 1, r, ln, rn));
        return res;
    }
    int query_sum(int x, int l, int r, int ln, int rn) {
        if (ln <= l && r <= rn) return sum[x];
        int mid = l + r >> 1, res = 0; pushdown(x, l, r, mid);
        if (mid >= ln) res += query_sum(ls, l, mid, ln, rn);
        if (mid + 1 <= rn) res += query_sum(rs, mid + 1, r, ln, rn);
        return res;
    }
} T;
signed main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    T.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 1) {
            int l = read() + 1, r = read() + 1, t = read(); T.add(1, 1, n, l, r, t);
        }
        if (opt == 2) {
            int l = read() + 1, r = read() + 1, t = read(); T.chu(1, 1, n, l, r, t);
        }
        if (opt == 3) {
            int l = read() + 1, r = read() + 1; printf("%lld\n", T.query_min(1, 1, n, l, r));
        }
        if (opt == 4) {
            int l = read() + 1, r = read() + 1; printf("%lld\n", T.query_sum(1, 1, n, l, r));
        }
        //for (int i = 1; i <= n; i++) printf("%d ", T.query_sum(1, 1, n, i, i)); printf("\n");
    }
    return 0;
}