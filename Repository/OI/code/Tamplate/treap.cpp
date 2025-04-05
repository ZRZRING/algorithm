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
int siz[N], cnt[N], val[N], rnd[N], son[N][2];
void pushup(int x) {siz[x] = siz[ls] + siz[rs] + cnt[x];}
void lup(int &x) {int y = ls; ls = son[y][1]; son[y][1] = x; siz[y] = siz[x]; pushup(x); x = y;}
void rup(int &x) {int y = rs; rs = son[y][0]; son[y][0] = x; siz[y] = siz[x]; pushup(x); x = y;}
void ins(int &x, int t) {
    if (!x) {
        x = ++tot; siz[x] = cnt[x] = 1; ls = rs = 0;
        val[x] = t; rnd[x] = rand(); return;
    }
    siz[x]++; if (val[x] == t) {cnt[x]++; pushup(x); return;}
    if (val[x] > t) {
        ins(ls, t); if (rnd[ls] < rnd[x]) lup(x);
    } else {
        ins(rs, t); if (rnd[rs] < rnd[x]) rup(x);
    }
}
bool del(int &x, int t) {
    if (!x) return 0;
    if (val[x] == t) {
        if (cnt[x] > 1) {siz[x]--; cnt[x]--; return 1;}
        if (!ls || !rs) {x = ls | rs; return 1;}
        rnd[ls] < rnd[rs] ? lup(x) : rup(x); return del(x, t);
    }
    if (del(son[x][val[x] < t] , t)) {siz[x]--; return 1;} else return 0;
}
int getrk(int t) {
    int x = rt, res = 1;
    while (x) {
        if (val[x] > t) x = ls;
        else { 
            res += siz[ls]; if (val[x] == t) return res;
            res += cnt[x]; x = rs;
        }
    }
    return res;
}
int query(int t) {
    int x = rt;
    while (x) {
        if (siz[ls] >= t) x = ls;
        else {
            t -= siz[ls] + cnt[x]; if (t <= 0) return val[x]; x = rs;
        }
    }
}
int pre(int t) {
    int x = rt, res = 0;
    while (x) {
        if (val[x] >= t) x = ls; else res = val[x], x = rs;
    }
    return res;
}
int suf(int t) {
    int x = rt, res = 0;
    while (x) {
        if (val[x] <= t) x = rs; else res = val[x], x = ls;
    }
    return res;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int opt = read(), t = read();
        if (opt == 1) ins(rt, t);
        if (opt == 2) del(rt, t);
        if (opt == 3) printf("%d\n", getrk(t));
        if (opt == 4) printf("%d\n", query(t));
        if (opt == 5) printf("%d\n", pre(t));
        if (opt == 6) printf("%d\n", suf(t));
    }
    return 0;
}