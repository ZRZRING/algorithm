#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls x << 1
#define rs x << 1 | 1
#define inf 1e9
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
inline long long lread() {
    long long sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m;
long long tsum[N], tag[N], a[N];
void pushup(int x) {
    tsum[x] = tsum[ls] + tsum[rs];
}
void build(int x, int l, int r) {
    if (l == r) {tsum[x] = a[l]; return;}
    int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r, long long t) {
    tsum[x] += (r - l + 1) * t; tag[x] += t;
}
void pushdown(int x, int l, int r, int mid) {
    if (tag[x]) {
        update(ls, l, mid, tag[x]); update(rs, mid + 1, r, tag[x]); tag[x] = 0;
    }
}
void modify(int x, int l, int r, int ln, int rn, long long t) {
    if (ln <= l && r <= rn) {update(x, l, r, t); return;}
    int mid = l + r >> 1; pushdown(x, l, r, mid);
    if (mid >= ln) modify(ls, l, mid, ln, rn, t);
    if (mid + 1 <= rn) modify(rs, mid + 1, r, ln, rn, t);
    pushup(x);
}
long long query(int x, int l, int r, int ln, int rn) {
    if (ln <= l && r <= rn) {return tsum[x];}
    int mid = l + r >> 1; long long res = 0; pushdown(x, l, r, mid);
    if (mid >= ln) res += query(ls, l, mid, ln, rn);
    if (mid + 1 <= rn) res += query(rs, mid + 1, r, ln, rn);
    return res;
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = lread();
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 1) {
            int l = read(), r = read(), t = read(); modify(1, 1, n, l, r, t);
        } else {
            int l = read(), r = read(); printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}