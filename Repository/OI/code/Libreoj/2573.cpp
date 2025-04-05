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
int n, m, dsq;
long long tmul[N];
void pushup(int x) {
    tmul[x] = tmul[ls] * tmul[rs] % dsq;
}
void build(int x, int l, int r) {
    if (l == r) {tmul[x] = 1; return;}
    int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    pushup(x);
}
void change(int x, int l, int r, int pos, int t) {
    if (l == r) {tmul[x] = t; return;}
    int mid = l + r >> 1;
    if (mid >= pos) change(ls, l, mid, pos, t);
    else change(rs, mid + 1, r, pos, t);
    pushup(x);
}
int main() {
    int T = read();
    while (T--) {
        n = read(); dsq = read(); build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            int opt = read(), t = read();
            if (opt == 1) {change(1, 1, n, i, t); printf("%d\n", tmul[1]);}
            if (opt == 2) {change(1, 1, n, t, 1); printf("%d\n", tmul[1]);}
        }
    }
    return 0;
}