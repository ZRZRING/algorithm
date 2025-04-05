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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, ans, cnt, a[N];

struct RES{int l, r;}res[N];

struct QUE {
    int dat[N], pos[N], head, tail;
} mx, mi;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int l = 1, r = 1;
    mx.head = mi.head = 1; mx.tail = mi.tail = 0;
    mi.dat[0] = inf; mx.dat[0] = -inf;
    for (r = 1; r <= n; r++) {
        while (a[r] > mx.dat[mx.tail] && mx.head <= mx.tail) mx.tail--;
        mx.dat[++mx.tail] = a[r]; mx.pos[mx.tail] = r;
        while (a[r] < mi.dat[mi.tail] && mi.head <= mi.tail) mi.tail--;
        mi.dat[++mi.tail] = a[r]; mi.pos[mi.tail] = r;
        printf("%d:\n", r);
        printf("max: "); for (int i = mx.head; i <= mx.tail; i++) printf("%d ", mx.dat[i]); printf("\n");
        printf("min: "); for (int i = mi.head; i <= mi.tail; i++) printf("%d ", mi.dat[i]); printf("\n");
        while (mx.dat[mx.head] - mi.dat[mi.head] > m) {
            if (mi.head == mi.tail && mx.head == mx.tail) break;
            if (mx.pos[mx.head] == mi.pos[mi.head]) mx.head++, mi.head++;
            else mx.pos[mx.head] < mi.pos[mi.head] ? mx.head++ : mi.head++;
        }
        printf("max: "); for (int i = mx.head; i <= mx.tail; i++) printf("%d ", mx.dat[i]); printf("\n");
        printf("min: "); for (int i = mi.head; i <= mi.tail; i++) printf("%d ", mi.dat[i]); printf("\n");
        l = min(mx.pos[mx.head], mi.pos[mi.head]);
        if (r - l + 1 == ans) res[++cnt] = (RES){l, r};
        if (r - l + 1 > ans) {
            ans = r - l + 1; cnt = 1; res[cnt] = (RES){l, r};
        }
    }
    printf("%d %d\n", ans, cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%d %d\n", res[i].l, res[i].r);
    }
    return 0;
}