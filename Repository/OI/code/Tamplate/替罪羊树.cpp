#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define alpha 0.75
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
int n, m, tot, rt, s[N], top;
int son[N][2], val[N], cnt[N], po[N], siz[N];
bool check(int x) {
    return cnt[x] && (alpha * po[x] <= 1.0 * max(po[ls], po[rs]) || 1.0 * siz[x] <= alpha * po[x]);
}
void pushup(int x) {
    po[x] = po[ls] + po[rs] + 1;
    siz[x] = siz[ls] + siz[rs] + cnt[x];
}
int build(int l, int r) {
    int mid = l + r >> 1, x = s[mid]; ls = rs = 0;
    if (mid > l) ls = build(l, mid - 1);
    if (mid < r) rs = build(mid + 1, r);
    pushup(x); return x;
}
void dfs(int x) {
    if (!x) return; dfs(ls); if (cnt[x]) s[++top] = x; dfs(rs);
}
void rebuild(int &x) {
    top = 0; dfs(x); x = build(1, top);
}
void ins(int &x, int t) {
    if (!x) {
        x = ++tot; val[x] = t; ls = rs = 0; cnt[x] = po[x] = siz[x] = 1; return;
    }
    if (val[x] == t) cnt[x]++; else ins(son[x][t > val[x]], t);
    pushup(x); if (check(x)) rebuild(x);
}
void del(int &x, int t) {
    if (!x) return; siz[x]--;
    if (val[x] == t) cnt[x]--; else del(son[x][t > val[x]], t);
    pushup(x); if (check(x)) rebuild(x);
}
int getrk(int t) {
    int x = rt, res = 1;
    while (x) {
        if (val[x] >= t) x = ls;
        else res += siz[ls] + cnt[x], x = rs;
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
    return 0;
}
int pre(int t) {
    //return query(getrk(t) - 1);
    int x = rt, res = 0;
    while (x) {
        if (val[x] >= t) x = ls;
        else {if (cnt[x]) res = val[x]; x = rs;}
    }
    return res;
}
int suf(int t) {
    //return query(getrk(t + 1));
    int x = rt, res = 0;
    while (x) {
        if (val[x] <= t) x = rs;
        else {if (cnt[x]) res = val[x]; x = ls;}
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
