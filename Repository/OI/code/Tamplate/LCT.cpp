#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls son[x][0]
#define rs son[x][1]
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
int n, m, val[N], a[N], son[N][2], fa[N], rev[N];
bool l_r(int x) {return x == son[fa[x]][1];}
bool isroot(int x) {return x != son[fa[x]][0] && x != son[fa[x]][1];}
void pushdown(int x) {if (!rev[x]) return; swap(ls, rs); rev[ls] ^= 1; rev[rs] ^= 1; rev[x] = 0;}
void update(int x) {if (!isroot(x)) update(fa[x]); pushdown(x);}
void pushup(int x) {val[x] = a[x] ^ val[ls] ^ val[rs];}
void rotate(int x) {
    int y = fa[x], z = fa[y], kind = l_r(x);
    if (!isroot(y)) son[z][l_r(y)] = x;
    son[y][kind] = son[x][kind ^ 1]; fa[son[x][kind ^ 1]] = y;
    son[x][kind ^ 1] = y; fa[y] = x; fa[x] = z;
    pushup(y); pushup(x);
}
void splay(int x) {
    update(x);
    for (int y = fa[x]; !isroot(x); y = fa[x]) {
        if (!isroot(y)) rotate(l_r(x) == l_r(y) ? y : x); rotate(x);
    }
}
void access(int x) {
    for (int y = 0; x; y = x, x = fa[x]) {
        splay(x); rs = y; pushup(x);
    }
}
int findrt(int x) {
	access(x); splay(x); while (ls) x = ls; splay(x); return x;
	//access(x); update(x); while (!isroot(x)) x = fa[x]; splay(x); return x;
}
void makeroot(int x) {access(x); splay(x); rev[x] ^= 1;}
void split(int x, int y) {makeroot(x); access(y); splay(y);}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) val[i] = a[i] = read();
    for (int i = 1; i <= m; i++) {
        int opt = read(), x = read(), y = read();
        if (opt == 0) {
            split(x, y); printf("%d\n", val[y]);
        }
        if (opt == 1) {
            if (findrt(x) != findrt(y)) makeroot(x), fa[x] = y;
        }
        if (opt == 2) {
            split(x, y); if (son[y][0] == x && !son[x][1]) son[y][0] = fa[x] = 0;
        }
        if (opt == 3) {
            access(x); splay(x); a[x] = y; pushup(x);
        }
    }
    return 0;
}
