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

const int N = 1e7 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct MAP {
    int l, r;
} pos[N];

int n, m;

namespace W1 {
    
    struct TREE {
        int ls[N], rs[N], sum[N], rt[N], cnt;
        int ins(int last, int l, int r, int pos) {
            int x = ++cnt; ls[x] = ls[last]; rs[x] = rs[last];
            sum[x] = sum[last] + 1; if (l == r) return x;
            int mid = l + r >> 1;
            if (mid >= pos) ls[x] = ins(ls[last], l, mid, pos);
            else rs[x] = ins(rs[last], mid + 1, r, pos);
            return x;
        }
        void build(int &x, int l, int r) {
            x = ++cnt; if (l == r) return; int mid = l + r >> 1;
            build(ls[x], l, mid); build(rs[x], mid + 1, r);
        }
    } L, R;
    
    int query(int l, int r, int tl, int tr, int k) {
        if (l == r) return l; int mid = l + r >> 1;
        printf("%d %d\n", tr, tl);
        int t = L.sum[L.ls[tr]] - R.sum[R.ls[tl]];
        if (t >= k) return query(l, mid, R.ls[tl], L.ls[tr], k);
        else return query(mid + 1, r, R.rs[tl], L.rs[tr], k - t);
    }

    void work() {
        L.build(L.rt[0], 1, n); R.build(R.rt[0], 1, n);
        for (int i = 1; i <= n; i++) {
            L.rt[i] = L.ins(L.rt[i - 1], 1, n, pos[i].l);
            R.rt[i] = R.ins(R.rt[i - 1], 1, n, pos[i].r);
        }
        for (int i = 1; i <= m; i++) {
            int l = read(), r = read(), k = read();
            if (k > r - l + 1) {printf("-1\n"); continue;}
            printf("%d\n", query(1, n, R.rt[l - 1], L.rt[r], k));
        }
    }
}

int main() {
    n = read(); m = read(); int flag1 = 1, flag2 = 1;
    for (int i = 1; i <= n; i++) {
        pos[i] = (MAP){read(), read()};
        // if (pos[i].l != 1 || pos[i].r != n) flag1 = 0;
    }
    W1::work();
    // if (flag1) {W1::work(); return 0;}
    return 0;
}