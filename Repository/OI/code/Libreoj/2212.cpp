#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define ls son[now][0]
#define rs son[now][1]
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N=500010;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, tot=1, rt;
int son[N][2], fa[N], siz[N], val[N], L[N], R[N], cnt[N];
map<int,int>pos;
void pushup(int now) {
    siz[now] = siz[ls] + siz[rs] + cnt[now];
    if (val[now])pos[val[now]] = now;else pos[R[now]] = now;
}
bool l_r(int x) {
    return x == son[fa[x]][1];
}
void rotate(int x, int &goal){
    int y = fa[x],z = fa[y],kind = l_r(x);
    if (y == goal) goal = x; else son[z][l_r(y)] = x;
    son[y][kind] = son[x][kind^1]; fa[son[x][kind^1]] = y;
    son[x][kind^1] = y; fa[y] = x; fa[x] = z;
    pushup(y); pushup(x);
}
void splay(int x, int &goal) {
    for (int y = fa[x]; x != goal; y = fa[x]){
        if (y != goal) rotate(l_r(x) == l_r(y) ? y : x, goal);
        rotate(x, goal);
    }
}
int find(int x) {
    int now = rt;
    while (1){
        if (x <= siz[ls]) now = ls;
        else{
            x -= siz[ls] + cnt[now];
            if (x <= 0) {
                if (val[now]) return val[now];
                else return R[now] + x;
            } now = rs;
        }
    }
}
int get_rank(int x, int t) {
    splay(x, rt);return siz[son[x][0]] + x - t + 1;
}
int pre() {
    int now = son[rt][0]; while (rs)now = rs; return now;
}
int suf() {
    int now = son[rt][1]; while (ls)now = ls; return now;
}
void top(int x) {
    splay(x, rt);int now = x;
    if (!ls) return;
    if (!rs) {
        rs = ls; ls = 0; return;
    }
    int y = suf(); son[y][0] = ls; fa[ls] = y; ls = 0; splay(y, rt);
}
void bot(int x) {
    splay(x, rt); int now = x;
    if (!rs) return;
    if (!ls) {
        ls = rs; rs = 0; return;
    }
    int y = pre(); son[y][1] = rs; fa[rs] = y; rs = 0; splay(y, rt);
}
void split(int x, int y) {
    int l = L[x], r = R[x]; if (l == r) return;
    if (l == y) {
        int now = ++tot;
        ls = son[x][0]; son[x][0] = now;
        fa[now] = x;
        L[now] = R[now] = y; L[x]++;
        cnt[now] = 1; cnt[x]--;
        pushup(now); pushup(x); splay(now, rt); splay(x, rt); return;
    }
    if (r == y) {
        int now = ++tot;
        rs = son[x][1]; son[x][1] = now;
        fa[now] = x;
        L[now] = R[now] = y; R[x]--;
        cnt[now] = 1; cnt[x]--;
        pushup(now); pushup(x); splay(now, rt); splay(x, rt); return;
    }
    int LS = ++tot, RS = ++tot;
    fa[son[x][0]] = LS; fa[son[x][1]] = RS; fa[LS] = x; fa[RS] = x;
    L[x] = R[x] = y; L[LS] = l; R[LS] = y-1; L[RS] = y+1; R[RS] = r;
    cnt[x] = 1; cnt[LS] = y-l; cnt[RS] = r-y;
    son[LS][0] = son[x][0]; son[RS][1] = son[x][1]; son[x][0] = LS; son[x][1] = RS;
    pushup(LS); pushup(RS); pushup(x); splay(LS, rt); splay(RS, rt); splay(x, rt);
}
int main() { file();
    n=read(); m=read();
    int last_ans = 0;
    rt=1; siz[1] = n; cnt[1] = n; L[1] = 1; R[1] = n; pos[n] = 1;
    for (int i = 1; i <= m; i++) {
        //printf("-------\n");
        int opt = read(), x = read() - last_ans;
        if (opt == 1) {
            int y = read() - last_ans;
            int c = pos.lower_bound(x) -> second;
            split(c, x); val[pos[x]] = y; pushup(pos[x]);
            printf("%d\n", last_ans = get_rank(pos[y], pos[y]));
        }
        if (opt == 2) {
            
            int c = pos.lower_bound(x) -> second; split(c, x);
            printf("%d\n", last_ans = get_rank(c, pos[x]));
            top(pos[x]);
        }
        if (opt == 3) {
            int c = pos.lower_bound(x) -> second; split(c, x);
            printf("%d\n", last_ans = get_rank(c, pos[x]));
            bot(pos[x]);
        }
        if (opt == 4) {
            printf("%d\n", last_ans = find(x));
        }
    }
    return 0;
}

//TODO: 应该是top或者bottom出了问题