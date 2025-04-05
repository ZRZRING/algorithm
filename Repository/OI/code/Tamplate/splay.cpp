#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define ls son[x][0]
#define rs son[x][1]
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
int n, m, tot, rt;
int son[N][2], val[N], tim[N], fa[N], siz[N];
void pushup(int x) {
    siz[x] = siz[ls] + siz[rs] + tim[x];
}
bool l_r(int x) {
    return x == son[fa[x]][1];
}
void rotate(int x, int &goal) {
    int y = fa[x], z = fa[y], kind = l_r(x);
    if (y == goal) goal = x; else son[z][l_r(y)] = x;
    son[y][kind] = son[x][kind ^ 1]; fa[son[x][kind ^ 1]] = y;
    son[x][kind ^ 1] = y; fa[y] = x; fa[x] = z;
    pushup(y); pushup(x);
}
void splay(int x, int &goal) {
    for (int y = fa[x]; x != goal; y = fa[x]) {
        if (y != goal) rotate(l_r(x) == l_r(y) ? y : x, goal);
        rotate(x, goal);
    }
}
void ins(int t) {
    if (!rt) {
        rt = ++tot; tim[rt] = siz[rt] = 1; val[rt] = t; return;
    }
    int x = rt, fat = 0;
    while (1) {
        if (val[x] == t) {
            tim[x]++; siz[x]++; pushup(fa[x]); splay(x, rt); return;
        }
        fat = x; x = son[x][t > val[x]];
        if (!x) {
            x = ++tot; tim[x] = siz[x] = 1; val[x] = t;
            son[fat][t > val[fat]] = x; fa[x] = fat;
            splay(x, rt); return;
        }
    }
}
int get_rank(int t) {
    int res = 1, x = rt;
    while (1) {
        if (t < val[x]) x = ls;
        else {
            res += siz[ls];
            if (t == val[x]) {splay(x, rt); return res;}
            res += tim[x]; x = rs;
        }
    }
    return res;
}
int query(int t) {
    int x = rt;
    while (1) {
        if (t <= siz[ls]) x = ls;
        else {
            t -= siz[ls] + tim[x];
            if (t <= 0) return val[x]; x = rs;
        }
    }
}
int pre() {
    int x = son[rt][0]; while (rs) x = rs; return x;
}
int suf() {
    int x = son[rt][1]; while (ls) x = ls; return x;
}
void del(int x) {
    get_rank(x); x = rt;
    if (tim[x] > 1) {tim[x]--; siz[x]--; return;}
    if (ls && rs) {
        int y = pre(); splay(y, rt); son[y][1] = rs; fa[rs] = y; return;
    }
    if (ls) {rt = ls; fa[rt] = 0; return;}
    if (rs) {rt = rs; fa[rt] = 0; return;}
    rt = 0;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int opt = read(), x = read();
        if (opt == 1) ins(x);
        if (opt == 2) del(x);
        if (opt == 3) printf("%d\n", get_rank(x));
        if (opt == 4) printf("%d\n", query(x));
        if (opt == 5) ins(x), printf("%d\n", val[pre()]), del(x);
        if (opt == 6) ins(x), printf("%d\n", val[suf()]), del(x);
    }
    return 0;
}