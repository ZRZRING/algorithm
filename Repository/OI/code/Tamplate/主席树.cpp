#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 8e7 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, dat[N], a[N], rt[N], cnt;
struct Seg_T{
    int ls[N], rs[N], sum[N];
    void build(int &x, int l, int r) {
        x = ++cnt; if (l == r) return; int mid = l + r >> 1;
        build(ls[x], l, mid); build(rs[x], mid + 1, r);
    }
    int insert(int last, int l, int r, int pos) {
        int x = ++cnt; ls[x] = ls[last]; rs[x] = rs[last];
        sum[x] = sum[last] + 1; if (l == r) return x;
        int mid = l + r >> 1;
        if (mid >= pos) ls[x] = insert(ls[last], l, mid, pos);
        else rs[x] = insert(rs[last], mid + 1, r, pos);
        return x;
    }
    int query(int l, int r, int tl, int tr, int pos) {
        if (l == r) return l;
        int mid = l + r >> 1, t = sum[ls[tr]] - sum[ls[tl]];
        if (t >= pos) return query(l, mid , ls[tl], ls[tr], pos);
        else return query(mid + 1, r, rs[tl], rs[tr], pos - t);
    }
} T;
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); dat[i] = a[i];
    }
    sort(dat + 1, dat + n + 1);
    int len = unique(dat + 1, dat + n + 1) - dat - 1;
    T.build(rt[0], 1, len);
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(dat + 1, dat + len + 1, a[i]) - dat;
        rt[i] = T.insert(rt[i - 1], 1, len, pos);
    }
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), k = read();
        printf("%d\n", dat[T.query(1, len, rt[l - 1], rt[r], k)]);
    }
    return 0;
}