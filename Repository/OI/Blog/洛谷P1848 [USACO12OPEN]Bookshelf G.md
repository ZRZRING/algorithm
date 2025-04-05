dp好题，首先$\mathcal{O}(N^2)$的dp非常好想，重点在于优化，观察式子

$$
dp[i] = \min_{w[i] - w[j] > L} (dp[j] + \max_{j \leq k \leq i} h[k])
$$

w的限制可以直接二分或预处理找一个左边界，转移的时候维护一棵线段树就好了

写了代码里一点注释

```cpp
//线段树维护的是算上当前点的贡献以后对于前面每个值的贡献
//但其实当前位置的h[i]只影响到上一个比h[i]大的点之后
//就在这个区间内记录上h[i]的贡献即可
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, L, pre[N], w[N], h[N], dp[N];
int s[N], top, tmin[N], tans[N], tag[N], sum[N];
void pushup(int x) {
    tans[x] = min(tans[ls], tans[rs]);
    tmin[x] = min(tmin[ls], tmin[rs]);
}
void pushdown(int x, int l, int r, int mid) {
    if (tag[x]) {
        tans[ls] = tmin[ls] + tag[x];
        tans[rs] = tmin[rs] + tag[x];
        tag[ls] = tag[rs] = tag[x]; tag[x] = 0;
    }
}
void init(int x, int l, int r, int goal) {
    if (l == r) {
        tans[x] = inf; tmin[x] = dp[l - 1]; return;
    }
    int mid = l + r >> 1;
    if (mid >= goal) init(ls, l, mid, goal);
    else init(rs, mid + 1, r, goal);
    pushup(x);
}
int query(int x, int l, int r, int ln, int rn) {
    if (ln <= l && r <= rn) return tans[x];
    int mid = l + r >> 1, ans = inf; pushdown(x, l, r, mid);
    if (mid >= ln) ans = min(ans, query(ls, l, mid, ln, rn));
    if (mid + 1 <= rn) ans = min(ans, query(rs, mid + 1, r, ln, rn));
    return ans;
}
void change(int x, int l, int r, int ln, int rn, int t) {
    if (ln <= l && r <= rn) {
        tans[x] = tmin[x] + t; tag[x] = t; return;
    }
    int mid = l + r >> 1; pushdown(x, l, r, mid);
    if (mid >= ln) change(ls, l, mid, ln, rn, t);
    if (mid + 1 <= rn) change(rs, mid + 1, r, ln, rn, t);
    pushup(x);
}
signed main() {
    n = read(); L = read();
    memset(tmin, 0x3f, sizeof(tmin));
    memset(tans, 0x3f, sizeof(tans));
    for (int i = 1; i <= n; i++) {
        h[i] = read(), w[i] = read(); sum[i] = sum[i - 1] + w[i];
    }
    s[++top] = 1;
    for (int i = 2; i <= n; i++) {
        while (top && h[i] > h[s[top]]) top--;
        if (top) pre[i] = s[top]; s[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        init(1, 1, n, i); change(1, 1, n, pre[i] + 1, i, h[i]);
        int l = lower_bound(sum, sum + n + 1, sum[i] - L) - sum;
        if (l < i) dp[i] = query(1, 1, n, l + 1, i);
    }
    printf("%lld\n", dp[n]);
    return 0;
}
```