#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
#define lowbit(x) (x & -x)
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
int n, m, cnt, tsum[N], ans[N];
struct node {
    int l, r, t, id;
} q[N], q1[N], q2[N];
int add(int x, int t) {
    for (; x <= n; x += lowbit(x)) tsum[x] += t;
}
int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tsum[x];
    return res;
}
void solve(int l, int r, int L, int R) {
    if (l > r) return;
    if (L == R) {
        for (int i = l; i <= r; i++) ans[q[i].id] = L; return;
    }
    int mid = L + R >> 1, cnt1 = 0, cnt2 = 0;
    for (int i = l; i <= r; i++) {
        if (q[i].id) { //区间查询
            int x = query(q[i].r) - query(q[i].l - 1);
            if (q[i].t <= x) {
                q1[++cnt1] = q[i];
            } else {
                q[i].t -= x; q2[++cnt2] = q[i];
            }
        } else { //插入一个数
            if (q[i].t <= mid) {
                q1[++cnt1] = q[i]; add(q[i].l, 1);
            } else {
                q2[++cnt2] = q[i];
            }
        }
    }
    for (int i = 1; i <= cnt1; i++) {
        if (!q1[i].id) add(q1[i].l, -1);
    }
    for (int i = l; i <= l + cnt1 - 1; i++) {
        q[i] = q1[i - l + 1];
    }
    for (int i = l + cnt1; i <= r; i++) {
        q[i] = q2[i - l - cnt1 + 1];
    }
    solve(l, l + cnt1 - 1, L, mid);
    solve(l + cnt1, r, mid + 1, R);
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        int x = read(); q[++cnt] = (node){i, i, x, 0};
    }
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), t = read();
        q[++cnt] = (node){l, r, t, i};
    }
    solve(1, cnt, -inf, inf);
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}